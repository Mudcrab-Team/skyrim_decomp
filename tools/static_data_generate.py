"""Discover and draft two static-data leaf families on the pinned local image.

    python tools/static_data_generate.py --exe /path/to/SkyrimSE.exe
    python tools/static_data_generate.py --exe /path/to/SkyrimSE.exe --out .local/static-data

Requires iced-x86==1.21.0. Without --out only counts are printed. The private
snapshot contains C++ units, verifier tasks and per-reference address bindings.
Add --compare to compile each unit with the contributor toolchain and compare
every member locally. Community boundaries and guessed signatures are hypotheses.
"""
import argparse
from collections import Counter, defaultdict
from dataclasses import dataclass
import hashlib
import importlib.util
import json
from pathlib import Path
import tempfile

import contrib
import pdb_types
from pecoff import PeImage, Reject, SCN_MEM_EXECUTE
import target_hashes


ROOT = Path(__file__).resolve().parents[1]
READERS = 'StaticDataReaders'
WRAPPERS = 'StaticObjectWrappers'


@dataclass(frozen=True)
class Member:
    rva: int
    size: int
    data: int
    width: int
    storage_type: str
    result_type: str
    callee: int | None = None

    @property
    def family(self):
        return READERS if self.callee is None else WRAPPERS

    @property
    def name(self):
        verb = 'Read' if self.callee is None else 'Invoke'
        return f'{verb}Static{self.rva:x}'

    @property
    def symbol(self):
        result = {'unsigned int': 'I', 'unsigned long long': '_K', 'float': 'M', 'double': 'N', 'void': 'X'}
        return f'?{self.name}@{self.family}@@SA{result[self.result_type]}XZ'


def classify(code, rva):
    from iced_x86 import Code, Decoder, Register

    instructions = list(Decoder(64, code, ip=rva))
    if len(instructions) != 2:
        return None
    load, end = instructions
    if load.memory_base != Register.RIP or not load.is_ip_rel_memory_operand or load.has_segment_prefix:
        return None
    if (load.code == Code.LEA_R64_M and load.op0_register == Register.RCX and load.len == 7
            and end.code == Code.JMP_REL32_64 and end.len == 5):
        return Member(rva, len(code), load.ip_rel_memory_address, 1, 'StaticStorage', 'void',
                      end.near_branch_target)
    if end.code != Code.RETNQ or end.len != 1:
        return None
    # The memory type describes the load. A zero-extending load returns an unsigned int.
    forms = {
        (Code.MOVZX_R32_RM8, Register.EAX, 7): (1, 'unsigned char', 'unsigned int'),
        (Code.MOVZX_R32_RM16, Register.EAX, 7): (2, 'unsigned short', 'unsigned int'),
        (Code.MOV_R32_RM32, Register.EAX, 6): (4, 'unsigned int', 'unsigned int'),
        (Code.MOV_R64_RM64, Register.RAX, 7): (8, 'unsigned long long', 'unsigned long long'),
        (Code.MOVSS_XMM_XMMM32, Register.XMM0, 8): (4, 'float', 'float'),
        (Code.MOVSD_XMM_XMMM64, Register.XMM0, 8): (8, 'double', 'double'),
    }
    form = forms.get((load.code, load.op0_register, load.len))
    if form:
        return Member(rva, len(code), load.ip_rel_memory_address, *form)
    return None


def boundaries(root):
    """Union published target and community extents, omitting conflicting sizes."""
    sizes = defaultdict(set)
    for row in target_hashes.load_manifest(root)['functions']:
        sizes[row['rva']].add(row['size'])
    directory = root / pdb_types.GENERATED / pdb_types.BOUNDARIES_DIR
    for path in sorted(directory.glob('*.tsv')):
        for line in path.read_text().splitlines():
            if line and not line.startswith('#'):
                rva, size = (int(field, 16) for field in line.split('\t'))
                sizes[rva].add(size)
    return {rva: next(iter(options)) for rva, options in sizes.items() if len(options) == 1}


def eligible_target(image, member, starts):
    try:
        data = image.section_for(member.data)
        if (data.name != '.data' or data.flags & SCN_MEM_EXECUTE or not data.flags & 0x80000000
                or member.data + member.width > data.vaddr + data.vsize or member.data % member.width):
            return False
        if member.callee is not None:
            return (member.callee in starts and not member.rva <= member.callee < member.rva + member.size
                    and bool(image.section_for(member.callee).flags & SCN_MEM_EXECUTE))
        return True
    except Reject:
        return False


def discover(image, extents, inventory):
    starts = set(extents) | {begin for begin, _, _ in image.runtime_functions()}
    matched = [(rva, rva + row['size']) for rva, row in inventory.items() if row['status'] == 'matched']
    candidates = []
    for rva, size in sorted(extents.items()):
        if size not in (7, 8, 9, 12):
            continue
        prior = inventory.get(rva)
        if prior and (prior['status'] == 'matched' or size != prior['size']):
            continue
        section, code = image.read(rva, size, 'candidate extent')
        if section.flags & SCN_MEM_EXECUTE:
            member = classify(code, rva)
            if (member and eligible_target(image, member, starts)
                    and not any(rva < end and begin < rva + size for begin, end in matched)):
                candidates.append(member)
    # Avoid declaring the same storage as incompatible objects, including partial overlaps.
    views = defaultdict(set)
    for m in candidates:
        for addr in range(m.data, m.data + m.width):
            views[addr].add((m.data, m.storage_type))
    return [m for m in candidates if all(len(views[addr]) == 1 for addr in range(m.data, m.data + m.width))]


def emit(root, family, members, build_id, label):
    """Write one translation unit and a standard local task for this family."""
    unit = Path('reconstruction/leaves') / family
    directory = root / 'tasks' / family
    directory.mkdir(parents=True)
    (root / unit.parent).mkdir(parents=True, exist_ok=True)
    prefix = ['// Source exposure: mixed (pinned image and community function boundaries).',
              f'// Boundary source: {label}',
              '// Code origin: original static-data template.',
              f'// {family}, methods and referenced symbols: GUESS(low) STANDIN; ownership and signatures unknown.',
              '// Adapted bodies: none']
    header = prefix + ['#pragma once', '']
    if family == WRAPPERS:
        header.append('struct StaticStorage;')
    symbols = {}
    for addr, typ in sorted({(m.data, m.storage_type) for m in members}):
        header.append(f'extern "C" {typ} StaticData{addr:x};')
        symbols[f'StaticData{addr:x}'] = dict(rva=addr, size=None)
    for callee in sorted({m.callee for m in members if m.callee is not None}):
        header.append(f'extern "C" void CallStatic{callee:x}(StaticStorage*);')
        symbols[f'CallStatic{callee:x}'] = dict(rva=callee, size=None)
    header.extend(['', f'struct {family}', '{'])
    source = prefix + [f'// 0x{m.rva:x} {family}::{m.name}' for m in members] + [f'#include "{family}.h"']
    functions = []
    for m in members:
        header.append(f'    static {m.result_type} {m.name}();')
        signature = f'{m.result_type} {family}::{m.name}()'
        body = (f'return StaticData{m.data:x};' if m.callee is None
                else f'CallStatic{m.callee:x}(&StaticData{m.data:x});')
        source.extend(['', signature, '{', f'    {body}', '}'])
        symbols[m.symbol] = dict(rva=m.rva, size=m.size)
        functions.append(dict(rva=m.rva, size=m.size, symbol=m.symbol))
    header.append('};')
    compiled = unit.with_suffix('.cpp').as_posix()
    (root / compiled).write_text('\n'.join(source) + '\n')
    (root / unit.with_suffix('.h')).write_text('\n'.join(header) + '\n')
    smap = dict(schema=1, build_id=build_id, symbols=symbols, folds=[])
    task = dict(task_schema=1, task_id=family, build_id=build_id, compiled=compiled,
                recipe=contrib.DEFAULT_RECIPE, symbols='symbols.json', functions=functions)
    for name, value in [('task.json', task), ('symbols.json', smap)]:
        (directory / name).write_text(json.dumps(value, indent=2) + '\n')
    return task, directory


def compare_members(ctx, root, manifest, image, tasks, build):
    import compare_runtime
    import unit_build
    import verify_function

    tool = contrib.check_toolchain(ctx)
    if tool['status'] != 'ok':
        raise ValueError(f'pinned contributor toolchain required ({tool["status"]})')
    recipe = (root / contrib.DEFAULT_RECIPE).read_bytes()
    counts = Counter()
    for task, directory in tasks:
        built = contrib.compile_unit(ctx, root, task['compiled'], task['recipe'], build / task['task_id'], tool)
        record = json.loads(built['build_record'].read_text())
        obj = built['object'].read_bytes()
        symbols = (directory / 'symbols.json').read_bytes()
        spec = dict(task, image_sha256=manifest['image_sha256'])
        for fn in task['functions']:
            request = unit_build.make_task(spec, fn, built['digest'], built['recipe_sha256'])
            report = verify_function.check_report(compare_runtime.compare(
                request, manifest, recipe, record, obj, image, symbols))
            counts[report['result']] += 1
            (directory / f'{fn["rva"]:x}.json').write_text(json.dumps(report, indent=2) + '\n')
    return counts


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--exe', required=True, type=Path)
    parser.add_argument('--out', type=Path, help='new snapshot directory beneath this checkout’s .local/')
    parser.add_argument('--compare', action='store_true', help='run the full local comparator and save reports')
    args = parser.parse_args()
    private = ROOT / '.local'
    out = args.out.resolve() if args.out else None
    if out and (private not in out.parents or out.exists()):
        parser.error('--out must be a new directory under this checkout’s .local/')
    if args.compare and out is None:
        parser.error('--compare requires --out for its reports')
    if importlib.util.find_spec('iced_x86') is None:
        parser.error('install iced-x86==1.21.0 in the Python environment used by this generator')
    manifest = json.loads((ROOT / 'builds/target.json').read_text())
    image = args.exe.read_bytes()
    if manifest['status'] != 'pinned' or hashlib.sha256(image).hexdigest() != manifest['image_sha256']:
        parser.error('image differs from the pinned build')
    progress = json.loads((ROOT / 'data/progress.json').read_text())
    inventory = {f['rva']: f for f in progress['functions'] if f['build_id'] == manifest['build_id']}
    members = discover(PeImage(image), boundaries(ROOT), inventory)
    print('Candidates:', dict(Counter(m.family for m in members)), flush=True)
    if out is None:
        return 0
    out.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=out.parent) as tmp:
        snapshot = Path(tmp) / 'snapshot'
        recipe = snapshot / contrib.DEFAULT_RECIPE
        recipe.parent.mkdir(parents=True)
        recipe.write_bytes((ROOT / contrib.DEFAULT_RECIPE).read_bytes())
        tasks = []
        for family in (READERS, WRAPPERS):
            rows = [m for m in members if m.family == family]
            if rows:
                tasks.append(emit(snapshot, family, rows, manifest['build_id'], pdb_types.label(pdb_types.tree_version())))
        counts = Counter()
        if args.compare:
            counts = compare_members(contrib.Ctx(), snapshot, manifest, image, tasks, Path(tmp) / 'build')
            print('Local comparator:', dict(counts))
        snapshot.rename(out)
    return int(bool(counts['fail']))


if __name__ == '__main__':
    raise SystemExit(main())
