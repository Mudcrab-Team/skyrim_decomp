"""Read function names and line ranges from relocated x64 COFF CodeView records."""

from collections import defaultdict
import struct

from pecoff import Reject, take, unpack

SYMBOLS, LINES, STRINGS, CHECKSUMS = 0xF1, 0xF2, 0xF3, 0xF4
PROCEDURES = {0x110F, 0x1110, 0x1146, 0x1147, 0x1155, 0x1156}
LINE_MASK = (1 << 24) - 1
LINE_MARKERS = {0, 0xF00F00, 0xFEEFEE}


def subsections(data):
    """Yield (kind, payload offset, payload) for a C13 .debug$S section."""
    if unpack('<I', data, 0, 'CodeView signature')[0] != 4:
        return
    pos = 4
    while pos < len(data):
        kind, length = unpack('<II', data, pos, 'CodeView subsection header')
        pos += 8
        yield kind, pos, take(data, pos, length, 'CodeView subsection')
        pos += (length + 3) & ~3


def cstring(data, pos):
    end = data.find(b'\0', pos)
    if end < 0 or pos >= len(data):
        raise Reject('invalid-codeview', 'unterminated CodeView string')
    return data[pos:end].decode('utf-8', 'replace')


def file_records(strings, checksums):
    files = {}
    pos = 0
    while pos < len(checksums):
        offset, size, kind = unpack('<IBB', checksums, pos, 'CodeView file checksum')
        files[pos] = (cstring(strings, offset), kind, take(checksums, pos + 6, size, 'CodeView checksum'))
        pos += (size + 9) & ~3
    return files


def address(obj, data, offset, relocs):
    """Resolve a SECREL/SECTION pair to (object section, offset), with no image input."""
    relative, segment = relocs.get(offset), relocs.get(offset + 4)
    if relative is None or segment is None or relative.kind != 0x0B or segment.kind != 0x0A:
        return None
    symbol, section_symbol = obj.symbols[relative.symbol], obj.symbols[segment.symbol]
    addend, section_addend = unpack('<IH', data, offset, 'CodeView address')
    if symbol.section > 0 and symbol.section == section_symbol.section and section_addend == 0:
        return symbol.section, symbol.value + addend
    return None


def procedures(obj, data, start, payload, relocs):
    pos = 0
    while pos < len(payload):
        length, kind = unpack('<HH', payload, pos, 'CodeView symbol header')
        record = take(payload, pos + 2, length, 'CodeView symbol')
        if length < 2:
            raise Reject('invalid-codeview', 'short CodeView symbol')
        if kind in PROCEDURES:
            location = address(obj, data, start + pos + 32, relocs)
            if location is not None:
                yield location, cstring(record, 37)
        pos += length + 2


def line_table(payload, files):
    """Return the contribution length and source transitions, retaining unknown boundaries."""
    _, _, flags, size = unpack('<IHHI', payload, 0, 'CodeView line header')
    pos = 12
    entries = {}
    while pos < len(payload):
        file_offset, count, block_size = unpack('<III', payload, pos, 'CodeView line block')
        if block_size != 12 + count * (12 if flags & 1 else 8):
            raise Reject('invalid-codeview', 'unexpected CodeView line block size')
        block = take(payload, pos + 12, block_size - 12, 'CodeView line entries')
        source = files.get(file_offset)
        for offset, bits in struct.iter_unpack('<II', block[:8 * count]):
            number = bits & LINE_MASK
            if offset < size:
                item = (source, number, bool(bits >> 31)) if source and number not in LINE_MARKERS else None
                if offset not in entries or item is not None and (entries[offset] is None or item[2]):
                    entries[offset] = item
        pos += block_size
    return size, sorted(entries.items())


def debug_records(obj):
    """Return procedure display names and line contributions keyed by COFF section and offset."""
    names, lines = {}, defaultdict(list)
    debug = [(sec, list(subsections(sec.data))) for sec in obj.sections
             if sec.name == '.debug$S' and sec.data]
    tables = [{kind: payload for kind, _, payload in parts if kind in (STRINGS, CHECKSUMS)}
              for _, parts in debug]
    strings = next((table[STRINGS] for table in tables if STRINGS in table), b'')
    checksums = next((table[CHECKSUMS] for table in tables if CHECKSUMS in table), b'')
    shared = file_records(strings, checksums)
    for (sec, parts), table in zip(debug, tables):
        relocs = {rel.offset: rel for rel in sec.relocs}
        files = (file_records(table.get(STRINGS, strings), table.get(CHECKSUMS, checksums))
                 if table else shared)
        for kind, offset, payload in parts:
            if kind == SYMBOLS:
                names.update(procedures(obj, sec.data, offset, payload, relocs))
            elif kind == LINES:
                location = address(obj, sec.data, offset, relocs)
                if location is not None:
                    size, entries = line_table(payload, files)
                    lines[location[0]].append((location[1], size, entries))
    return names, lines
