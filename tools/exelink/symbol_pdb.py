"""Link a synthetic PE and PDB with CodeView records projected onto the requested RVAs."""

from collections import Counter
from itertools import groupby
import json
from pathlib import Path
import subprocess
from tempfile import TemporaryDirectory

from codeview import CHECKSUMS, LINES, STRINGS, SYMBOLS

TEXT_RVA = 0x1000
S_END, S_GPROC32 = 0x0006, 0x1110
PROVENANCE_STREAM = '/reconstruction/name-origins'


def quoted(text):
    """Quote UTF-8 bytes for assembly string literals and symbol names."""
    if not isinstance(text, str) or '\0' in text or not text:
        raise ValueError('expected a nonempty CodeView string')
    return '"' + ''.join(chr(b) if 32 <= b < 127 and b not in (34, 92) else f'\\{b:03o}'
                         for b in text.encode('utf-8')) + '"'


def subsection(out, kind, label):
    print(f'.long {kind}, .L{label}_end-.L{label}', f'.L{label}:', sep='\n', file=out)


def record(out, kind, label):
    print(f'.short .L{label}_end-.L{label}', f'.L{label}:', f'.short {kind}', sep='\n', file=out)


def end(out, label):
    print('.p2align 2', f'.L{label}_end:', sep='\n', file=out)


def cv_address(out, start, offset=0):
    print(f'.secrel32 {start}+{offset}', f'.secidx {start}', sep='\n', file=out)


def line_runs(rows):
    """Partition ranges at gaps so the PDB has no line for uncovered instructions."""
    run = []
    for row in rows:
        if run and run[-1]['offset'] + run[-1]['length'] != row['offset']:
            yield run
            run = []
        run.append(row)
    if run:
        yield run


def write_assembly(out, functions):
    files = sorted({line['file'] for fn in functions for line in fn['lines']})
    file_offsets = {path: index * 8 for index, path in enumerate(files)}
    name_counts = Counter(fn['linkage_name'] for fn in functions)
    entries = []
    print('.text', file=out)
    previous = TEXT_RVA
    for index, fn in enumerate(functions):
        rva, size = fn['rva'], fn['size']
        if rva < previous or size <= 0 or rva + size > 1 << 32:
            raise ValueError('symbol ranges must be ascending, nonoverlapping and within the carrier range')
        start = f'.Lfunc{index}'
        name = fn['linkage_name']
        if name_counts[name] > 1:
            name = f'{name}@@rva_{rva:x}'
        public = quoted(name)
        print(f'.org {rva - TEXT_RVA}', f'.def {public}; .scl 2; .type 32; .endef',
              f'.globl {public}', f'{public}:', f'{start}:', sep='\n', file=out)
        entries.append((fn, start))
        previous = rva + size
    print(f'.org {previous - TEXT_RVA}', '.section .debug$S,"dr"', '.long 4', sep='\n', file=out)
    subsection(out, SYMBOLS, 'symbols')
    for index, (fn, start) in enumerate(entries):
        label = f'proc{index}'
        record(out, S_GPROC32, label)
        print(f'.long 0,0,0,{fn["size"]},0,0,0', file=out)
        cv_address(out, start)
        print('.byte 0', f'.asciz {quoted(fn["name"])}', sep='\n', file=out)
        end(out, label)
        print(f'.short 2,{S_END}', file=out)
    end(out, 'symbols')

    for index, (fn, start) in enumerate(entries):
        for run_index, run in enumerate(line_runs(fn['lines'])):
            label = f'lines{index}_{run_index}'
            offset = run[0]['offset']
            size = run[-1]['offset'] + run[-1]['length'] - offset
            subsection(out, LINES, label)
            cv_address(out, start, offset)
            print('.short 0', f'.long {size}', sep='\n', file=out)
            for path, items in groupby(run, key=lambda row: row['file']):
                block = list(items)
                print(f'.long {file_offsets[path]},{len(block)},{12 + len(block) * 8}', file=out)
                for row in block:
                    flags = row['line'] | (int(row['statement']) << 31)
                    print(f'.long {row["offset"] - offset},{flags}', file=out)
            end(out, label)

    if files:
        subsection(out, CHECKSUMS, 'files')
        for index in range(len(files)):
            print(f'.long .Lfile{index}-.Lstrings,0', file=out)
        end(out, 'files')
        subsection(out, STRINGS, 'strings')
        print('.byte 0', file=out)
        for index, path in enumerate(files):
            print(f'.Lfile{index}:', f'.asciz {quoted(path)}', sep='\n', file=out)
        end(out, 'strings')


def write_pdb(mapping, pdb, source_root, clang='clang', linker='lld-link'):
    """Emit the PDB and its empty-code PE carrier, preserving their linked identity."""
    functions = mapping['functions']
    pdb = Path(pdb)
    if pdb.suffix.lower() != '.pdb' or not functions:
        raise ValueError('PDB generation needs a .pdb output and at least one function')
    pdb.parent.mkdir(parents=True, exist_ok=True)
    carrier = pdb.with_suffix('.dll')
    with TemporaryDirectory(prefix='pdb-build-', dir=pdb.parent) as temporary:
        work = Path(temporary)
        with (work / 'symbols.s').open('w', encoding='ascii') as out:
            write_assembly(out, functions)
        provenance = {str(fn['rva']): fn['labels'] for fn in functions if fn['labels']}
        (work / 'origins.json').write_text(json.dumps({'build_id': mapping['build_id'], 'labels': provenance}),
                                           encoding='utf-8')
        commands = [
            [clang, '--target=x86_64-pc-windows-msvc', '-c', 'symbols.s', '-o', 'symbols.obj'],
            [linker, '/dll', '/noentry', '/nodefaultlib', '/debug:full', '/opt:noref',
             f'/out:{carrier.name}', f'/pdb:{pdb.name}', f'/pdbaltpath:{pdb.name}',
             f'/pdbsourcepath:{source_root}', f'/pdbstream:{PROVENANCE_STREAM}=origins.json', 'symbols.obj'],
        ]
        for command in commands:
            result = subprocess.run(command, cwd=work, capture_output=True)
            if result.returncode:
                (pdb.parent / 'pdb-build.log').write_bytes(result.stderr + result.stdout)
                raise ValueError(f'{Path(command[0]).name} failed; see private pdb-build.log')
        (work / pdb.name).replace(pdb)
        (work / carrier.name).replace(carrier)
    return carrier
