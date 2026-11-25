"""Private snapshot and comparator workflow shared by indexed leaf-family generators."""
import argparse
from collections import Counter, defaultdict
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


def candidates(image, extents, inventory, sizes, classify):
    """Decode complete executable entries outside previously matched ranges."""
    matched = [(rva, rva + row['size']) for rva, row in inventory.items() if row['status'] == 'matched']
    for rva, size in sorted(extents.items()):
        if size not in sizes:
            continue
        prior = inventory.get(rva)
        if prior and (prior['status'] == 'matched' or prior['size'] != size):
            continue
        section, code = image.read(rva, size, 'candidate extent')
        if section.flags & SCN_MEM_EXECUTE:
            member = classify(code, rva)
            if member and not any(rva < end and begin < rva + size for begin, end in matched):
                yield member


def indexed_callee(image, member, starts):
    if member.callee not in starts or member.rva <= member.callee < member.rva + member.size:
        return False
    try:
        return bool(image.section_for(member.callee).flags & SCN_MEM_EXECUTE)
    except Reject:
        return False


def write_unit(root, family, build_id, header, source, symbols, functions, *, area='leaves'):
    unit = Path('reconstruction') / area / family
    directory = root / 'tasks' / family
    directory.mkdir(parents=True)
    (root / unit.parent).mkdir(parents=True, exist_ok=True)
    compiled = unit.with_suffix('.cpp').as_posix()
    (root / compiled).write_text('\n'.join(source) + '\n', newline='\n')
    (root / unit.with_suffix('.h')).write_text('\n'.join(header) + '\n', newline='\n')
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


def run(description, discover, emit, *, split=None):
    parser = argparse.ArgumentParser(description=description, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--exe', required=True, type=Path)
    parser.add_argument('--out', type=Path, help='new snapshot directory beneath this checkout’s .local/')
    parser.add_argument('--compare', action='store_true', help='run the full local comparator and save reports')
    parser.add_argument('--only', type=Path, help='file of whitespace-separated hexadecimal RVAs; keep only those members')
    if split:
        parser.add_argument('--split', choices=('development', 'held-out'), help='generate only this validation partition')
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
    if split and args.split:
        members = [m for m in members if split(m) == args.split]
    if args.only:
        wanted = {int(word, 16) for word in args.only.read_text().split()}
        members = [m for m in members if m.rva in wanted]
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
        for family in sorted({m.family for m in members}):
            rows = [m for m in members if m.family == family]
            tasks.append(emit(snapshot, family, rows, manifest['build_id'], pdb_types.label(pdb_types.tree_version())))
        counts = Counter()
        if args.compare:
            counts = compare_members(contrib.Ctx(), snapshot, manifest, image, tasks, Path(tmp) / 'build')
            print('Local comparator:', dict(counts))
        snapshot.rename(out)
    return int(bool(counts['fail']))
