#!/usr/bin/env python3
"""Regenerate reconstruction/generated/crashlogger_pdb/ from the CrashLogger community PDB.

The community PDBs (Nexus mod 59818, CrashLogger Contributors, alandtse/CrashLoggerSSE) carry class
layouts and function names for the pinned build. This tool reads the PDB's TPI stream and symbol
streams itself (no llvm-pdbutil needed) and rewrites the whole generated directory
deterministically: one C++ layout header per class, a function-name map keyed by RVA, a type index
and a README. Nothing else is written, and the PDB is never copied.

    python3 tools/pdb_types.py generate <SkyrimSE.pdb> [--version 2026.10.24] [--out DIR]
    python3 tools/pdb_types.py rva 0x1234        # owning class and header of a function
    python3 tools/pdb_types.py class TESRace     # header path of a class
    python3 tools/pdb_types.py check             # the committed tree is well formed

Every name and layout taken from the output into a unit carries the label
`CRASHLOGGER_PDB(59818@<version>)`. A layout is a community guess about the game's types, not
evidence: byte-compare before trusting it.
"""
import argparse
import hashlib
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GENERATED = 'reconstruction/generated/crashlogger_pdb'
SOURCE_ID = '59818'
DEFAULT_VERSION = '2026.10.24'
TYPES_DIR = 'types'
NAMES_DIR = 'names'
SHARD_BITS = 20  # one names file per MiB of RVA, to stay under the scanner's per-file size limit
INDEX_FILE = 'types.tsv'
README = 'README.md'
MAX_IDENT = 96


def label(version=DEFAULT_VERSION):
    return f'CRASHLOGGER_PDB({SOURCE_ID}@{version})'


# --- MSF container and PDB streams -------------------------------------------------------------

MSF_MAGIC = b'Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0'


class Msf:
    """The multi-stream file under a PDB: `stream(i)` returns the bytes of stream i."""

    def __init__(self, data):
        if data[:32] != MSF_MAGIC:
            raise ValueError('not a PDB 7.00 (MSF) file')
        self.data = data
        self.block_size, _, self.block_count, dir_bytes, _, map_block = struct.unpack_from('<IIIIII', data, 32)
        dir_blocks = -(-dir_bytes // self.block_size)
        list_blocks = struct.unpack_from(f'<{dir_blocks}I', data, map_block * self.block_size)
        directory = self.blocks(list_blocks, dir_bytes)
        count = struct.unpack_from('<I', directory, 0)[0]
        sizes = struct.unpack_from(f'<{count}I', directory, 4)
        pos = 4 + 4 * count
        self.streams = []
        for size in sizes:
            n = 0 if size == 0xFFFFFFFF else -(-size // self.block_size)
            self.streams.append((0 if size == 0xFFFFFFFF else size, struct.unpack_from(f'<{n}I', directory, pos)))
            pos += 4 * n

    def blocks(self, numbers, size):
        bs = self.block_size
        return b''.join(self.data[b * bs:(b + 1) * bs] for b in numbers)[:size]

    def stream(self, index):
        size, blocks = self.streams[index]
        return self.blocks(blocks, size)


def cstring(buf, pos):
    end = buf.index(b'\0', pos)
    return buf[pos:end].decode('utf-8', 'replace'), end + 1


# Leaf kinds used by the TPI reader.
LF_MODIFIER, LF_POINTER, LF_PROCEDURE, LF_ARGLIST = 0x1001, 0x1002, 0x1008, 0x1201
LF_FIELDLIST, LF_BITFIELD, LF_ARRAY, LF_CLASS, LF_STRUCTURE = 0x1203, 0x1205, 0x1503, 0x1504, 0x1505
LF_UNION, LF_ENUM = 0x1506, 0x1507
LF_MEMBER, LF_ENUMERATE, LF_INDEX, LF_BCLASS, LF_VFUNCTAB = 0x150D, 0x1502, 0x1404, 0x1400, 0x1409
LF_STMEMBER, LF_NESTTYPE, LF_METHOD, LF_ONEMETHOD = 0x150E, 0x1510, 0x150F, 0x1511
LF_VBCLASS, LF_IVBCLASS = 0x1401, 0x1402
NUMERIC = {0x8000: '<b', 0x8001: '<h', 0x8002: '<H', 0x8003: '<i', 0x8004: '<I', 0x8009: '<q', 0x800A: '<Q'}

SIMPLE = {
    0x03: 'void', 0x08: 'long', 0x10: 'signed char', 0x11: 'short', 0x12: 'long', 0x13: 'long long',
    0x20: 'unsigned char', 0x21: 'unsigned short', 0x22: 'unsigned long', 0x23: 'unsigned long long',
    0x30: 'bool', 0x31: 'bool', 0x32: 'bool', 0x33: 'bool',
    0x40: 'float', 0x41: 'double', 0x42: 'long double',
    0x68: 'signed char', 0x69: 'unsigned char', 0x70: 'char', 0x71: 'wchar_t', 0x72: 'short',
    0x73: 'unsigned short', 0x74: 'int', 0x75: 'unsigned int', 0x76: 'long long', 0x77: 'unsigned long long',
    0x7A: 'char16_t', 0x7B: 'char32_t',
}
SIMPLE_SIZE = {
    0x03: 0, 0x08: 4, 0x10: 1, 0x11: 2, 0x12: 4, 0x13: 8, 0x20: 1, 0x21: 2, 0x22: 4, 0x23: 8,
    0x30: 1, 0x31: 2, 0x32: 4, 0x33: 8, 0x40: 4, 0x41: 8, 0x42: 8,
    0x68: 1, 0x69: 1, 0x70: 1, 0x71: 2, 0x72: 2, 0x73: 2, 0x74: 4, 0x75: 4, 0x76: 8, 0x77: 8, 0x7A: 2, 0x7B: 4,
}


def numeric(buf, pos):
    value = struct.unpack_from('<H', buf, pos)[0]
    pos += 2
    if value < 0x8000:
        return value, pos
    fmt = NUMERIC[value]
    return struct.unpack_from(fmt, buf, pos)[0], pos + struct.calcsize(fmt)


class Tpi:
    """Type records of the TPI stream, parsed on demand and addressed by type index."""

    def __init__(self, stream):
        _, header_size, self.begin, self.end, _ = struct.unpack_from('<IIIII', stream, 0)
        self.stream = stream
        self.records = {}
        pos, index = header_size, self.begin
        while index < self.end:
            length, kind = struct.unpack_from('<HH', stream, pos)
            self.records[index] = (kind, pos + 4, pos + 2 + length)
            pos += 2 + length
            index += 1
        self.cache = {}

    def body(self, index):
        kind, start, end = self.records[index]
        return kind, self.stream[start:end]

    def record(self, index):
        """The parsed record of `index` as a dict with a 'kind' key, or None for a simple type."""
        if index < self.begin:
            return None
        got = self.cache.get(index)
        if got is None:
            kind, buf = self.body(index)
            got = self.cache[index] = {'kind': kind, 'index': index, **self.parse(kind, buf)}
        return got

    def parse(self, kind, buf):
        if kind in (LF_CLASS, LF_STRUCTURE):
            count, prop, field, derived, vshape = struct.unpack_from('<HHIII', buf, 0)
            size, pos = numeric(buf, 16)
            name, pos = cstring(buf, pos)
            unique = cstring(buf, pos)[0] if prop & 0x200 else ''
            return {'name': name, 'unique': unique, 'fwd': bool(prop & 0x80), 'field': field, 'size': size,
                    'derived': derived, 'vshape': vshape}
        if kind == LF_UNION:
            count, prop, field = struct.unpack_from('<HHI', buf, 0)
            size, pos = numeric(buf, 8)
            name, pos = cstring(buf, pos)
            unique = cstring(buf, pos)[0] if prop & 0x200 else ''
            return {'name': name, 'unique': unique, 'fwd': bool(prop & 0x80), 'field': field, 'size': size}
        if kind == LF_ENUM:
            count, prop, utype, field = struct.unpack_from('<HHII', buf, 0)
            name, pos = cstring(buf, 12)
            unique = cstring(buf, pos)[0] if prop & 0x200 else ''
            return {'name': name, 'unique': unique, 'fwd': bool(prop & 0x80), 'field': field, 'utype': utype}
        if kind == LF_POINTER:
            referent, attrs = struct.unpack_from('<II', buf, 0)
            return {'to': referent, 'mode': (attrs >> 5) & 7, 'ptr_size': (attrs >> 13) & 0x3F}
        if kind == LF_MODIFIER:
            return {'to': struct.unpack_from('<I', buf, 0)[0]}
        if kind == LF_ARRAY:
            elem, idx = struct.unpack_from('<II', buf, 0)
            size, _ = numeric(buf, 8)
            return {'elem': elem, 'size': size}
        if kind == LF_BITFIELD:
            base, length, position = struct.unpack_from('<IBB', buf, 0)
            return {'base': base, 'length': length, 'position': position}
        if kind == LF_PROCEDURE:
            ret, conv, _, count, args = struct.unpack_from('<IBBHI', buf, 0)
            return {'ret': ret, 'args': args, 'count': count}
        if kind == LF_ARGLIST:
            count = struct.unpack_from('<I', buf, 0)[0]
            return {'types': list(struct.unpack_from(f'<{count}I', buf, 4))}
        if kind == LF_FIELDLIST:
            return self.parse_fields(buf)
        return {}

    def parse_fields(self, buf):
        members, enumerators, cont, pos = [], [], None, 0
        while pos + 2 <= len(buf):
            kind = struct.unpack_from('<H', buf, pos)[0]
            pos += 2
            if kind == LF_MEMBER:
                attr, ty = struct.unpack_from('<HI', buf, pos)
                offset, p = numeric(buf, pos + 6)
                name, pos = cstring(buf, p)
                members.append((offset, ty, name))
            elif kind == LF_ENUMERATE:
                attr = struct.unpack_from('<H', buf, pos)[0]
                value, p = numeric(buf, pos + 2)
                name, pos = cstring(buf, p)
                enumerators.append((name, value))
            elif kind == LF_INDEX:
                cont = struct.unpack_from('<I', buf, pos + 2)[0]
                pos += 6
            elif kind in (LF_BCLASS, LF_VBCLASS, LF_IVBCLASS):
                _, p = numeric(buf, pos + 6)
                pos = p
            elif kind == LF_VFUNCTAB:
                pos += 6
            elif kind == LF_STMEMBER:
                name, pos = cstring(buf, pos + 6)
            elif kind == LF_NESTTYPE:
                name, pos = cstring(buf, pos + 6)
            elif kind == LF_METHOD:
                name, pos = cstring(buf, pos + 6)
            elif kind == LF_ONEMETHOD:
                name, pos = cstring(buf, pos + 6)
            else:
                break
            while pos < len(buf) and buf[pos] >= 0xF0:
                pos += 1
        return {'members': members, 'enumerators': enumerators, 'cont': cont}


def read_symbols(msf):
    """(sections, publics, procs): section virtual addresses, public functions and module procedures
    as lists of (rva, name) / (rva, name, type index)."""
    dbi = msf.stream(3)
    sym_stream = struct.unpack_from('<H', dbi, 20)[0]
    mod_size, contrib_size, section_map, source_info, type_map, _, dbg_size, ec_size = \
        struct.unpack_from('<iiiiiIii', dbi, 24)
    dbg_start = 64 + mod_size + contrib_size + section_map + source_info + type_map + ec_size
    streams = struct.unpack_from(f'<{dbg_size // 2}H', dbi, dbg_start) if dbg_size else ()
    headers = msf.stream(streams[5]) if len(streams) > 5 and streams[5] != 0xFFFF else b''
    sections = [struct.unpack_from('<I', headers, i * 40 + 12)[0] for i in range(len(headers) // 40)]
    publics, procs = [], []
    syms = msf.stream(sym_stream)
    pos = 0
    while pos + 4 <= len(syms):
        length, kind = struct.unpack_from('<HH', syms, pos)
        if kind == 0x110E:  # S_PUB32
            flags, offset, segment = struct.unpack_from('<IIH', syms, pos + 4)
            name = cstring(syms, pos + 14)[0]
            if flags & 2 and 0 < segment <= len(sections):
                publics.append((sections[segment - 1] + offset, name))
        pos += 2 + length
    # Module symbol streams: S_GPROC32 / S_LPROC32 records.
    pos, mods = 64, []
    end = 64 + mod_size
    while pos < end:
        stream_index, sym_bytes = struct.unpack_from('<HI', dbi, pos + 34)[0], struct.unpack_from('<I', dbi, pos + 36)[0]
        name, p = cstring(dbi, pos + 64)
        _, p = cstring(dbi, p)
        pos = (p + 3) & ~3
        mods.append((stream_index, sym_bytes))
    for stream_index, sym_bytes in mods:
        if stream_index == 0xFFFF:
            continue
        data = msf.stream(stream_index)[4:sym_bytes]
        p = 0
        while p + 4 <= len(data):
            length, kind = struct.unpack_from('<HH', data, p)
            if kind in (0x1110, 0x1111):
                type_index, offset, segment = struct.unpack_from('<IIH', data, p + 4 + 24)
                if 0 < segment <= len(sections):
                    procs.append((sections[segment - 1] + offset, cstring(data, p + 4 + 35)[0], type_index))
            p += 2 + length
    return sections, publics, procs


# --- identifiers ---------------------------------------------------------------------------------

AUTO_NAME = re.compile(r'^(?:FUN|thunk_FUN|LAB|SUB|sub|DAT|PTR|switchD|caseD|UNK|BYTE|DWORD)_[0-9a-fA-F]+$')
NON_IDENT = re.compile(r'[^A-Za-z0-9_]+')
KEYWORDS = frozenset('''alignas alignof and asm auto bool break case catch char class const constexpr continue
decltype default delete do double else enum explicit export extern false float for friend goto if inline int long
mutable namespace new noexcept not nullptr operator or private protected public register return short signed
sizeof static struct switch template this throw true try typedef typeid typename union unsigned using virtual
void volatile while xor wchar_t'''.split())


def short_hash(text, n=8):
    return hashlib.sha256(text.encode('utf-8')).hexdigest()[:n]


def identifier(name):
    """A C++ identifier for a PDB type name: `::` becomes `__`. A name with other punctuation (templates)
    or over MAX_IDENT characters is cut and tagged with a hash of the original, so two names never share
    one and the identifier stays the same from one regeneration to the next."""
    raw = name.replace('::', '__')
    ident = NON_IDENT.sub('_', raw).strip('_') or 'unnamed'
    if ident[0].isdigit() or ident in KEYWORDS:
        ident = '_' + ident
    if len(ident) > MAX_IDENT or NON_IDENT.search(raw):
        ident = ident[:MAX_IDENT - 9].rstrip('_') + '_' + short_hash(name)
    return ident


def member_name(name, used):
    ident = NON_IDENT.sub('_', name) or 'field'
    if ident[0].isdigit() or ident in KEYWORDS:
        ident = '_' + ident
    base, n = ident, 1
    while ident in used:
        n += 1
        ident = f'{base}_{n}'
    used.add(ident)
    return ident


# --- type model ----------------------------------------------------------------------------------

AGG_KINDS = (LF_CLASS, LF_STRUCTURE, LF_UNION, LF_ENUM)
UNIT_TYPE = {1: 'unsigned char', 2: 'unsigned short', 4: 'unsigned int', 8: 'unsigned long long'}
sys.setrecursionlimit(20000)


class Model:
    """Struct, union and enum definitions of a TPI. A name can stand for several unrelated types (the
    exporter drops namespaces) and for the same type once per object file, so definitions are told apart
    by a structural key: equal keys are one type, different keys under one name are variants."""

    def __init__(self, tpi):
        self.tpi = tpi
        self.by_unique, self.fwd_names = {}, set()
        defs_by_name = defaultdict(list)
        for index in sorted(tpi.records):
            if tpi.records[index][0] in AGG_KINDS:
                rec = tpi.record(index)
                if not rec['name']:
                    continue
                if rec['fwd']:
                    self.fwd_names.add(rec['name'])
                else:
                    defs_by_name[rec['name']].append(index)
                    if rec['unique']:
                        self.by_unique.setdefault(rec['unique'], index)
        self._keys, self._active = {}, set()
        self.variants = {}   # name -> [(key, lowest definition index)] fullest first
        for name, indexes in defs_by_name.items():
            seen = {}
            for index in indexes:
                seen.setdefault(self.key(index), index)
            self.variants[name] = sorted(seen.items(), key=lambda kv: (
                -(self.tpi.record(kv[1]).get('size') or 0), -self.member_count(kv[1]), kv[0]))
        self.idents, taken, folded = {}, set(), set()
        for name in sorted(self.variants):
            for rank, (key, _) in enumerate(self.variants[name]):
                ident = identifier(name)
                if rank:
                    ident = ident[:MAX_IDENT - 9].rstrip('_') + '_' + key[:8]
                if ident in taken or ident.lower() in folded:
                    ident = ident[:MAX_IDENT - 9].rstrip('_') + '_' + short_hash(name + key)
                taken.add(ident)
                folded.add(ident.lower())
                self.idents[(name, key)] = ident
        self.opaque = {}
        self._taken, self._folded = taken, folded

    def fields(self, index):
        rec = self.tpi.record(index)
        members, enumerators, field = [], [], rec['field']
        while field and field >= self.tpi.begin:
            fl = self.tpi.record(field)
            members += fl['members']
            enumerators += fl['enumerators']
            field = fl['cont']
        return members, enumerators

    def member_count(self, index):
        members, enumerators = self.fields(index)
        return len(members) + len(enumerators)

    def resolve(self, ti):
        """Strip modifiers: (type index, record), the record being None for a simple type."""
        while ti >= self.tpi.begin:
            rec = self.tpi.record(ti)
            if rec['kind'] != LF_MODIFIER:
                return ti, rec
            ti = rec['to']
        return ti, None

    def def_of(self, rec):
        """The definition index of a struct, union or enum record (forward references follow their unique
        name), or None when the PDB never defines it."""
        if not rec['fwd']:
            return self.tpi_index(rec)
        got = self.by_unique.get(rec['unique'])
        if got is None and rec['name'] in self.variants:
            got = self.variants[rec['name']][0][1]
        return got

    def tpi_index(self, rec):
        return rec['index']

    def ident_of(self, index):
        rec = self.tpi.record(index)
        return self.idents[(rec['name'], self.key(index))]

    def opaque_ident(self, name):
        if name not in self.opaque:
            ident = identifier(name)
            if ident in self._taken or ident.lower() in self._folded:
                ident = ident[:MAX_IDENT - 9].rstrip('_') + '_' + short_hash(name)
            self._taken.add(ident)
            self._folded.add(ident.lower())
            self.opaque[name] = ident
        return self.opaque[name]

    def key(self, index):
        got = self._keys.get(index)
        if got is not None:
            return got
        if index in self._active:
            return 'cycle'
        self._active.add(index)
        rec = self.tpi.record(index)
        members, enumerators = self.fields(index)
        parts = [str(rec['kind']), rec['name'], str(rec.get('size')), str(self.tkey(rec['utype']) if rec['kind'] == LF_ENUM else '')]
        parts += [f'{o}:{n}:{self.tkey(t)}' for o, t, n in members]
        parts += [f'{n}={v}' for n, v in enumerators]
        self._active.discard(index)
        got = self._keys[index] = hashlib.sha256('\n'.join(parts).encode('utf-8')).hexdigest()[:12]
        return got

    def tkey(self, ti, by_ref=False):
        ti, rec = self.resolve(ti)
        if rec is None:
            return str(ti)
        kind = rec['kind']
        if kind == LF_POINTER:
            return f'P{rec["mode"]}({self.tkey(rec["to"], True)})'
        if kind == LF_ARRAY:
            return f'A{rec["size"]}({self.tkey(rec["elem"], by_ref)})'
        if kind == LF_BITFIELD:
            return f'B{rec["length"]}.{rec["position"]}({self.tkey(rec["base"])})'
        if kind == LF_PROCEDURE:
            args = self.tpi.record(rec['args'])['types'] if rec['args'] >= self.tpi.begin else []
            return f'F({self.tkey(rec["ret"], True)};' + ','.join(self.tkey(a, True) for a in args) + ')'
        if kind in AGG_KINDS:
            index = self.def_of(rec)
            if by_ref or index is None:
                return f'N{rec["name"]}'
            return self.key(index)
        return f'K{kind}'

    def sizeof(self, ti):
        ti, rec = self.resolve(ti)
        if rec is None:
            if ti >= 0x100:
                return 8 if (ti >> 8) & 0xF in (6, 0xA) else 4
            return SIMPLE_SIZE.get(ti & 0xFF, 0)
        kind = rec['kind']
        if kind == LF_POINTER:
            return rec['ptr_size'] or 8
        if kind == LF_ARRAY:
            return rec['size']
        if kind == LF_BITFIELD:
            return self.sizeof(rec['base'])
        if kind == LF_ENUM:
            return self.sizeof(rec['utype']) if rec['utype'] else 4
        if kind in AGG_KINDS:
            index = self.def_of(rec)
            return (self.tpi.record(index).get('size') or 0) if index is not None else 0
        return 8


class Declarator:
    """Renders a type index as a C++ declaration and collects which types it needs."""

    def __init__(self, model, renderer):
        self.model, self.renderer = model, renderer
        self.complete = set()   # identifiers needed whole (by value)
        self.declared = {}      # identifier -> 'struct'|'union', needed by name only
        self.seen = []          # identifiers used by the declaration being rendered
        self.elaborate = False  # spell `struct X` so a member may share its type's name
        self.opaque = False     # a by-value type the PDB only forward-declares

    def decl(self, ti, inner='', by_value=True):
        """The declaration `<type> <inner>` for type index `ti` ('' inner declares an abstract type)."""
        m = self.model
        ti, rec = m.resolve(ti)
        if rec is None:
            if ti >= 0x100 and (ti >> 8) & 0xF in (6, 0xA, 4):
                return f'{SIMPLE.get(ti & 0xFF, "void")}* {inner}'.rstrip()
            return f'{SIMPLE.get(ti & 0xFF, "unsigned char")} {inner}'.rstrip()
        kind = rec['kind']
        if kind == LF_POINTER:
            if rec['mode'] in (2, 3):  # member pointers: layout only, not callable
                return f'void* {inner}'.rstrip()
            sym = '&&' if rec['mode'] == 4 else '&' if rec['mode'] == 1 else '*'
            return self.decl(rec['to'], sym + inner, by_value=False)
        if kind == LF_ARRAY:
            elem = m.sizeof(rec['elem'])
            count = rec['size'] // elem if elem else 0
            paren = f'({inner})' if inner.startswith(('*', '&')) else inner
            return self.decl(rec['elem'], f'{paren}[{count}]', by_value)
        if kind == LF_PROCEDURE:
            types = m.tpi.record(rec['args'])['types'] if rec['args'] >= m.tpi.begin else []
            args = ', '.join('void*' if t == 3 else self.decl(t, '', by_value=False) for t in types)
            paren = f'({inner})' if inner.startswith(('*', '&')) else inner
            return self.decl(rec['ret'], f'{paren}({args or "void"})', by_value=False)
        if kind in AGG_KINDS:
            index = m.def_of(rec)
            keyword = 'union' if kind == LF_UNION else 'enum' if kind == LF_ENUM else 'struct'
            if index is None:
                ident = m.opaque_ident(rec['name'])
                if by_value:
                    self.opaque = True
                else:
                    self.declared[ident] = 'struct'
            else:
                ident = m.ident_of(index)
                if by_value or kind == LF_ENUM:
                    self.complete.add(ident)
                else:
                    self.declared[ident] = keyword
            self.seen.append(ident)
            tag = f'{keyword} ' if self.elaborate else ''
            return f'{tag}{ident} {inner}'.rstrip()
        return f'unsigned char {inner}'.rstrip()


def fix_pointer_spacing(text):
    return re.sub(r'([A-Za-z0-9_>])\s+([*&]+)', r'\1\2 ', text).replace('* (', '*(').replace('*  ', '* ')


def layout_items(model, members, is_union):
    """Group sorted members into ('field', offset, type, name), ('bytes', offset, count, name) and
    ('bits', offset, [(absolute bit, length, name)]) items. Adjacent `void` members are the exporter's
    one-byte placeholders for unknown bytes; adjacent bitfields form one run."""
    items = []
    for offset, ti, name in members:
        _, rec = model.resolve(ti)
        last = items[-1] if items else None
        if is_union:
            items.append(('field', offset, ti, name))
        elif rec is not None and rec['kind'] == LF_BITFIELD:
            bit = (offset * 8 + rec['position'], rec['length'], name)
            if last and last[0] == 'bits':
                last[2].append(bit)
            else:
                items.append(('bits', offset, [bit]))
        elif model.resolve(ti) == (3, None):
            if last and last[0] == 'bytes' and last[1] + last[2] == offset:
                items[-1] = ('bytes', last[1], last[2] + 1, last[3])
            else:
                items.append(('bytes', offset, 1, f'undefined_{offset:x}'))
        else:
            items.append(('field', offset, ti, name))
    return items


def bit_unit(offset, bits, limit):
    """(unit bytes, unit count) of the storage that holds a bitfield run exactly as the PDB places it, or
    None. MSVC packs same-typed bitfields in declaration order inside aligned units, so a unit must start
    at the run's first byte, keep every field inside one unit and stay clear of the next member."""
    last = max(b + n for b, n, _ in bits)
    span = -(-(last - offset * 8) // 8)
    for unit in (8, 4, 2, 1):
        units = -(-span // unit)
        if offset % unit or offset + units * unit > limit:
            continue
        if all((b - offset * 8) // (unit * 8) == (b + n - 1 - offset * 8) // (unit * 8) for b, n, _ in bits):
            return unit, units
    return None


def pick_pack(aligns, total):
    """(pack, alignment): the largest `#pragma pack` under which members keep the PDB's offsets and the
    size stays a multiple of the alignment; pack None means natural alignment works."""
    natural = max([a for _, a in aligns] or [1])
    if all(o % a == 0 for o, a in aligns) and total % natural == 0:
        return None, natural
    for pack in (8, 4, 2, 1):
        eff = [(o, min(a, pack)) for o, a in aligns]
        top = max([a for _, a in eff] or [1])
        if all(o % a == 0 for o, a in eff) and total % top == 0:
            return pack, top
    return 1, 1


class Rendered:
    def __init__(self, text, complete, declared, pack, align, notes):
        self.text, self.complete, self.declared = text, complete, declared
        self.pack, self.align, self.notes = pack, align, notes


class Renderer:
    """Turns definitions into header text, once per definition."""

    def __init__(self, model):
        self.model, self.memo = model, {}

    def render(self, index):
        key = self.model.key(index)
        got = self.memo.get(key)
        if got is None:
            rec = self.model.tpi.record(index)
            got = self.memo[key] = (self.enum if rec['kind'] == LF_ENUM else self.struct)(index)
        return got

    def align_of(self, ti):
        m = self.model
        ti, rec = m.resolve(ti)
        if rec is None:
            return 8 if ti >= 0x100 else min(max(SIMPLE_SIZE.get(ti & 0xFF, 1), 1), 8)
        kind = rec['kind']
        if kind == LF_POINTER:
            return 8
        if kind == LF_ARRAY:
            return self.align_of(rec['elem'])
        if kind == LF_BITFIELD:
            return self.align_of(rec['base'])
        if kind == LF_ENUM:
            return min(max(m.sizeof(rec['utype']), 1), 8) if rec['utype'] else 4
        if kind in AGG_KINDS:
            index = m.def_of(rec)
            return self.render(index).align if index is not None else 1
        return 8

    def enum(self, index):
        m = self.model
        rec = m.tpi.record(index)
        ident = m.ident_of(index)
        _, enumerators = m.fields(index)
        utype = rec['utype'] if rec['utype'] else 0x74
        under = Declarator(m, self).decl(utype)
        bits = max(m.sizeof(utype), 1) * 8
        signed = 'unsigned' not in under and under not in ('bool', 'char16_t', 'char32_t', 'wchar_t')
        used, lines = set(), []
        for ename, value in enumerators:
            value &= (1 << bits) - 1
            if signed and value >= 1 << (bits - 1):
                value -= 1 << bits
            lines.append(f'    {member_name(ename, used)} = {value},')
        text = [f'enum class {ident} : {under}' + ' {'] + (lines or ['    // no enumerators in the PDB']) + ['};']
        return Rendered('\n'.join(text) + '\n', set(), {}, None, min(bits // 8, 8), [])

    def struct(self, index):
        m = self.model
        rec = m.tpi.record(index)
        ident = m.ident_of(index)
        is_union = rec['kind'] == LF_UNION
        total = rec['size']
        members, _ = m.fields(index)
        members = members if is_union else sorted(members, key=lambda mem: mem[0])
        items = layout_items(m, members, is_union)
        dec = Declarator(m, self)
        used, body, aligns, notes = set(), [], [], []
        state = {'end': 0, 'pad': 0}

        def boundary(i):
            first = items[i]
            limit = first[1] * 8
            if first[0] == 'bits':
                limit = max(b + n for b, n, _ in first[2])
            elif first[0] == 'bytes':
                limit = (first[1] + first[2]) * 8
            for later in items[i + 1:]:
                if later[1] * 8 >= limit and later[1] > first[1]:
                    return later[1]
            return total

        def pad_to(offset):
            if not is_union and offset > state['end']:
                body.append(f'    unsigned char _pad_{state["pad"]}[{offset - state["end"]}];')
                state['pad'] += 1
                state['end'] = offset

        for i, item in enumerate(items):
            kind, offset = item[0], item[1]
            if not is_union and offset < state['end']:
                body.append(f'    // overlaps an earlier member, left out: +0x{offset:x} '
                            f'{item[3] if kind != "bits" else "bitfields"}')
                continue
            pad_to(offset)
            if kind == 'bytes':
                body.append(f'    unsigned char {member_name(item[3], used)}[{item[2]}];')
                aligns.append((offset, 1))
                state['end'] = offset + item[2]
            elif kind == 'bits':
                bits = item[2]
                fit = bit_unit(offset, bits, boundary(i))
                if fit is None:
                    last = max(b + n for b, n, _ in bits)
                    span = -(-(last - offset * 8) // 8)
                    body.append(f'    unsigned char _bits_{offset:x}[{span}];  // bitfields placed across unit '
                                'boundaries; bit ranges follow')
                    body += [f'    //   {nm}: bits {b - offset * 8}..{b - offset * 8 + n - 1}' for b, n, nm in bits]
                    aligns.append((offset, 1))
                    state['end'] = offset + span
                    continue
                unit, units = fit
                utype, cursor = UNIT_TYPE[unit], offset * 8
                for b, n, nm in bits:
                    if b > cursor:
                        body.append(f'    {utype} : {b - cursor};')
                    body.append(f'    {utype} {member_name(nm, used)} : {n};')
                    cursor = b + n
                aligns.append((offset, unit))
                state['end'] = offset + units * unit
            else:
                ti, mname = item[2], member_name(item[3], used)
                size = m.sizeof(ti)
                slot = boundary(i) - offset
                _, mrec = m.resolve(ti)
                if not is_union and 0 < slot < size and mrec is not None and mrec['kind'] == LF_ENUM \
                        and slot in UNIT_TYPE:
                    body.append(f'    {UNIT_TYPE[slot]} {mname};  // {mrec["name"]} in the PDB is wider than this slot')
                    aligns.append((offset, slot))
                    state['end'] = offset + slot
                    continue
                if not is_union and 0 < slot < size:
                    what = mrec['name'] if mrec is not None and 'name' in mrec else 'its type'
                    body.append(f'    unsigned char {mname}[{slot}];  // {what} is {size} bytes in the PDB, '
                                f'more than this slot')
                    aligns.append((offset, 1))
                    state['end'] = offset + slot
                    continue
                dec.seen, dec.opaque = [], False
                text = fix_pointer_spacing(dec.decl(ti, mname))
                if dec.opaque:
                    width = slot if slot > 0 else 0
                    body.append(f'    unsigned char {mname}[{width}];  // type only forward-declared in the PDB'
                                if width else f'    // {mname}: type only forward-declared in the PDB')
                    aligns.append((offset, 1))
                    state['end'] = offset + width
                    continue
                if mname in dec.seen:
                    dec.seen, dec.elaborate = [], True
                    text = fix_pointer_spacing(dec.decl(ti, mname))
                    dec.elaborate = False
                body.append(f'    {text};')
                aligns.append((offset, self.align_of(ti)))
                state['end'] = max(state['end'], offset + size)
        if not is_union:
            if total > state['end']:
                pad_to(total)
            elif state['end'] > total:
                notes.append(f'members run {state["end"] - total} bytes past the PDB size')
        pack, align = pick_pack(aligns, total)
        keyword = 'union' if is_union else 'struct'
        lines = []
        if pack:
            lines.append(f'#pragma pack(push, {pack})')
        lines.append(f'{keyword} {ident}' + ' {')
        lines += body or ['    // no members in the PDB']
        lines.append('};')
        if pack:
            lines.append('#pragma pack(pop)')
        if total:
            lines.append(f'static_assert(sizeof({ident}) == {total}, "{ident} layout differs from the PDB");')
        complete = dec.complete - {ident}
        declared = {k: v for k, v in dec.declared.items() if k != ident and k not in complete}
        return Rendered('\n'.join(lines) + '\n', complete, declared, pack, align, notes)


def file_text(model, renderer, name, key, index, version):
    got = renderer.render(index)
    rec = model.tpi.record(index)
    out = [f'// {label(version)}']
    size = f'; size 0x{rec["size"]:x}' if rec['kind'] != LF_ENUM else ''
    out.append(f'// PDB name: {name}{size}')
    if len(model.variants[name]) > 1:
        rank = [k for k, _ in model.variants[name]].index(key)
        out.append(f'// one of {len(model.variants[name])} different PDB types sharing this name'
                   + ('; the fullest' if rank == 0 else ''))
    out += [f'// {n}' for n in got.notes]
    out += ['#pragma once', '']
    out += [f'#include "{r}.h"' for r in sorted(got.complete)]
    out += [f'{kw} {ident};' for ident, kw in sorted(got.declared.items())]
    if got.complete or got.declared:
        out.append('')
    return '\n'.join(out) + got.text


# --- generation ----------------------------------------------------------------------------------

def owner_candidates(name):
    """Possible class names of a function's public name, most specific first."""
    base = re.sub(r'_(?:[0-9A-Fa-f]{8,16})$', '', name)
    depth, cut = 0, -1
    for i, ch in enumerate(base):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == ':' and depth == 0 and base[i:i + 2] == '::':
            cut = i
    out = []
    if cut > 0:
        out.append(base[:cut])
    parts = base.split('__')
    for n in range(len(parts) - 1, 0, -1):
        out.append('__'.join(parts[:n]))
        out.append('::'.join(parts[:n]))
    return out


def names_map(publics, procs):
    """RVA -> name for every function that has a name a person chose (not a decompiler placeholder)."""
    names = {}
    for rva, name, *_ in procs + [(r, n) for r, n in publics]:
        if not AUTO_NAME.match(name):
            names[rva] = name
    return dict(sorted(names.items()))


def build_files(pdb, version):
    """{relative path: text} of the whole generated directory for one PDB."""
    msf = Msf(Path(pdb).read_bytes())
    tpi = Tpi(msf.stream(2))
    model = Model(tpi)
    renderer = Renderer(model)
    _, publics, procs = read_symbols(msf)
    files, rows = {}, []
    for name in sorted(model.variants):
        for rank, (key, index) in enumerate(model.variants[name]):
            ident = model.idents[(name, key)]
            files[f'{TYPES_DIR}/{ident}.h'] = file_text(model, renderer, name, key, index, version)
            rec = tpi.record(index)
            kind = {LF_ENUM: 'enum', LF_UNION: 'union'}.get(rec['kind'], 'struct')
            rows.append(f'{name}\t{ident}\t{kind}\t{rec.get("size") or 0}\t{"-" if rank == 0 else key[:8]}')
    files[INDEX_FILE] = (f'# {label(version)}\n# pdb name, identifier (header types/<identifier>.h), kind, size in bytes, '
                         'variant (- for the fullest type of that name)\n' + '\n'.join(rows) + '\n')
    names = names_map(publics, procs)
    shards = defaultdict(list)
    for rva, name in names.items():
        shards[rva >> SHARD_BITS].append(f'0x{rva:x}\t{name}\n')
    for shard, lines in sorted(shards.items()):
        files[f'{NAMES_DIR}/{shard:02x}.tsv'] = f'# {label(version)}\n# rva, public name; RVAs 0x{shard << SHARD_BITS:x}-0x{((shard + 1) << SHARD_BITS) - 1:x}\n' + ''.join(lines)
    files[README] = readme_text(version, msf, len(rows), len(names), model)
    return files


def readme_text(version, msf, types, functions, model):
    guid = msf.stream(1)[12:28]
    guid_text = '{%08X-%04X-%04X-%s-%s}' % (struct.unpack('<IHH', guid[:8]) + (guid[8:10].hex().upper(), guid[10:].hex().upper()))
    return f'''<!-- {label(version)} -->
# CrashLogger community PDB output

Names and class layouts generated from the community PDB published with CrashLogger.

- Source: Nexus Mods mod {SOURCE_ID}, CrashLogger Contributors (alandtse/CrashLoggerSSE), version {version}.
- PDB signature: {guid_text}. The PDB itself is never committed.
- Label: every name or layout taken from here into a unit carries `{label(version)}`.
- Regenerate with `python3 tools/pdb_types.py generate <SkyrimSE.pdb> --version {version}`; the whole directory is
  rewritten deterministically, so a diff shows exactly what a new PDB changed.

## Contents

- `types/<identifier>.h`: one layout header per class, union or enum ({types} types). Each holds the PDB's fields and
  offsets with explicit padding, includes the headers of the types it holds by value, forward-declares the ones it
  only points to, and ends with a `static_assert` on the PDB size. Nothing includes them until a unit does.
- `types.tsv`: PDB name, identifier, kind and size of every type.
- `names/<NN>.tsv`: RVA to public name for the {functions} functions whose name is not a decompiler placeholder, one
  file per MiB of RVA (`NN` is the RVA shifted right by 20).

## Cautions

- These are community reconstructions of the game's types, not the game's own declarations. A field name or
  offset is a guess until the compiled function matches.
- A base class appears as an ordinary member named `_base`, `_base_<Name>`: the PDB has no inheritance records.
  The first base carries the virtual-table pointer.
- Names containing `::`, `<`, `>` or other punctuation are written with `__` and `_` in identifiers; `types.tsv`
  maps the PDB spelling to the identifier. Template instantiations are kept, with long names cut and tagged by a
  hash of the original.
- The exporter drops namespaces, so one name can stand for several unrelated types. Each distinct type gets its
  own header; the fullest keeps the plain identifier and the others add a hash suffix ({sum(1 for v in model.variants.values() if len(v) > 1)} names have more than one).
- `const` and `volatile` are dropped; member and function pointers are plain `void*`.
- An RVA belongs to the build the PDB was made for (`builds/target.json`); do not reuse it for another build.
'''


def write_tree(files, out):
    """Replace `out` with exactly `files`."""
    out = Path(out)
    if out.exists():
        for path in sorted(out.rglob('*'), reverse=True):
            path.unlink() if path.is_file() or path.is_symlink() else path.rmdir()
    for rel, text in files.items():
        path = out / rel
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(text.encode('utf-8'))


# --- lookup (reads the committed tree) -------------------------------------------------------------

def load_tree(root=ROOT):
    base = Path(root) / GENERATED
    names, types = {}, {}
    for shard in sorted((base / NAMES_DIR).glob('*.tsv')) if (base / NAMES_DIR).is_dir() else []:
        for line in shard.read_text(encoding='utf-8').splitlines():
            if line and not line.startswith('#'):
                rva, name = line.split('\t', 1)
                names[int(rva, 16)] = name
    if (base / INDEX_FILE).is_file():
        for line in (base / INDEX_FILE).read_text(encoding='utf-8').splitlines():
            if line and not line.startswith('#'):
                name, ident, kind, size, variant = line.split('\t')
                if variant == '-':
                    types[name] = (ident, kind, int(size))
    return names, types


def lookup_rva(rva, root=ROOT, tree=None):
    """{'name', 'class', 'header'} for a function's RVA, or None when the tree has no name for it.
    'class' and 'header' are None when the public name does not lead to a known class."""
    names, types = tree or load_tree(root)
    name = names.get(rva)
    if name is None:
        return None
    by_ident = {ident: pdb for pdb, (ident, _, _) in types.items()}
    for candidate in owner_candidates(name):
        pdb = candidate if candidate in types else by_ident.get(candidate)
        if pdb is None and identifier(candidate) in by_ident:
            pdb = by_ident[identifier(candidate)]
        if pdb is not None:
            ident = types[pdb][0]
            return {'name': name, 'class': pdb, 'header': f'{GENERATED}/{TYPES_DIR}/{ident}.h'}
    return {'name': name, 'class': None, 'header': None}


def lookup_class(name, root=ROOT, tree=None):
    _, types = tree or load_tree(root)
    got = types.get(name) or next((v for k, v in types.items() if v[0] == name), None)
    return f'{GENERATED}/{TYPES_DIR}/{got[0]}.h' if got else None


def tree_version(root=ROOT):
    """The version in the committed names map's label line, or the default when there is none."""
    try:
        first = (Path(root) / GENERATED / README).read_text(encoding='utf-8').split('\n', 1)[0]
    except OSError:
        return DEFAULT_VERSION
    found = re.search(r'CRASHLOGGER_PDB\(59818@([0-9.]+)\)', first)
    return found.group(1) if found else DEFAULT_VERSION


def hint_for_rvas(rvas, root=ROOT, tree=None):
    """The lines `./sr start` prints about class layouts: one per class header, for the first function that
    belongs to it. Names are suggested separately (tools/crashlogger_pdb.py); empty when the committed tree
    holds no layout for the functions' classes."""
    tree = tree or load_tree(root)
    text = label(tree_version(root))
    lines, headers = [], set()
    for rva in rvas:
        got = lookup_rva(rva, root, tree)
        if not got or not got['header'] or got['header'] in headers:
            continue
        headers.add(got['header'])
        include = got['header'].split('reconstruction/', 1)[1]
        lines.append(f"PDB layout for {got['name']}: {got['header']} (community guess; copy the members you need "
                     f'into your unit\'s header, or include it as "{include}" when the unit does not declare the '
                     f'class itself; a name or layout taken from it gets the label {text})')
    return lines


def hint_for_rva(rva, root=ROOT, tree=None):
    """The layout hint of one function, or None when the committed tree has no layout for its class."""
    return next(iter(hint_for_rvas([rva], root, tree)), None)


# --- validation (used by lint) -------------------------------------------------------------------

LABEL_RE = re.compile(r'CRASHLOGGER_PDB\(59818@[0-9]{4}\.[0-9]{2}\.[0-9]{2}\)')


def file_problems(root, name):
    """Findings for one generated file: an allowed kind whose first line carries the label."""
    path = Path(root) / name
    suffix = path.suffix
    if suffix not in ('.h', '.tsv', '.md'):
        return [f'{name}: only .h, .tsv and .md files belong in {GENERATED}']
    first = path.read_text(encoding='utf-8', errors='replace').split('\n', 1)[0]
    if not LABEL_RE.search(first):
        return [f'{name}: first line must carry CRASHLOGGER_PDB(59818@<version>)']
    return []


def tree_problems(root=ROOT):
    """Findings for the committed generated directory."""
    base = Path(root) / GENERATED
    return [p for path in sorted(base.rglob('*')) if path.is_file()
            for p in file_problems(root, path.relative_to(root).as_posix())] if base.is_dir() else []


def is_generated(name):
    return str(name).replace('\\', '/').startswith(GENERATED + '/')


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = p.add_subparsers(dest='cmd', required=True)
    g = sub.add_parser('generate')
    g.add_argument('pdb')
    g.add_argument('--version', default=DEFAULT_VERSION)
    g.add_argument('--out', default=str(ROOT / GENERATED))
    r = sub.add_parser('rva')
    r.add_argument('rva')
    c = sub.add_parser('class')
    c.add_argument('name')
    sub.add_parser('check')
    args = p.parse_args(argv)
    if args.cmd == 'generate':
        files = build_files(args.pdb, args.version)
        write_tree(files, args.out)
        print(f'wrote {len(files)} files under {args.out}')
    elif args.cmd == 'rva':
        got = lookup_rva(int(args.rva, 16))
        print(got if got else 'no public name for that RVA in the generated names map')
        return 0 if got else 1
    elif args.cmd == 'class':
        got = lookup_class(args.name)
        print(got or 'unknown class')
        return 0 if got else 1
    else:
        problems = tree_problems()
        print('\n'.join(problems) or 'pdb_types: PASS')
        return 1 if problems else 0
    return 0


if __name__ == '__main__':
    sys.exit(main())
