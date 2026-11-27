#!/usr/bin/env python3
"""Run tools/compare.py on compiled sibling functions against their lead targets.

A symbol map is derived from the target itself: every candidate relocation is decoded at the same
offset in the target bytes and must resolve to one RVA per symbol. A pair whose references disagree
is reported as unresolvable rather than forced. Inputs and reports stay under .local/.
"""
import argparse, hashlib, json, os, re, struct, subprocess, sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPO / 'tools'))

OBJDUMP = os.environ.get('LLVM_OBJDUMP', '/opt/homebrew/opt/llvm/bin/llvm-objdump')
FRAME_HANDLER = 22714324  # image-wide RVA of the C++ EH personality routine, from the project symbol map
TAIL = {'REL32': 0, 'REL32_1': 1, 'REL32_2': 2, 'REL32_3': 3, 'REL32_4': 4, 'REL32_5': 5}


def sha(b):
    return hashlib.sha256(b).hexdigest()


_cache = {}


def relocs_of(obj, sym):
    if obj not in _cache:
        out = subprocess.run([OBJDUMP, '-d', '-r', '--no-show-raw-insn', str(obj)], capture_output=True, text=True).stdout
        cur, table = None, {}
        for line in out.splitlines():
            m = re.match(r'^([0-9a-f]{16}) <(.+)>:$', line)
            if m:
                cur = m.group(2)
                continue
            m = re.match(r'^\s+([0-9a-f]+):\s+IMAGE_REL_AMD64_(\w+)\s+(\S+)', line)
            if m and cur:
                table.setdefault(cur, []).append((int(m.group(1), 16), m.group(2), m.group(3)))
        _cache.clear()
        _cache[obj] = table
    return _cache[obj].get(sym, [])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--scores', required=True)
    ap.add_argument('--objdir', required=True)
    ap.add_argument('--image', required=True)
    ap.add_argument('--out', required=True)
    ap.add_argument('--only', default='identical', help="'identical' or 'all'")
    ap.add_argument('--limit', type=int, default=1000)
    ap.add_argument('--tag', default='f3x64', help='task id and source path prefix; names the index the candidates came from')
    a = ap.parse_args()
    out = Path(a.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    img = Path(a.image)
    image_bytes = img.read_bytes()
    manifest = json.loads((REPO / 'builds/target.json').read_text())
    recipe = REPO / 'reconstruction/recipes/msvc-19.16.27054-o2.json'
    rsha = sha(recipe.read_bytes())
    S = [s for s in json.load(open(a.scores)) if a.only == 'all' or s['identical']]
    S.sort(key=lambda s: s['key'][0])
    S = S[:a.limit]
    results = []
    for s in S:
        obj = Path(a.objdir) / (s['key'][0] + '.obj')
        sym = s['key'][1]
        rva, size = s['rva'], s['size']
        res = {'rva': rva, 'symbol_hash': sha(sym.encode())[:10]}
        try:
            tbytes = image_bytes[pe_off(image_bytes, rva): pe_off(image_bytes, rva) + size]
            syms, bad = {}, None
            for off, typ, name in relocs_of(obj, sym):
                if typ not in TAIL:
                    bad = f'reloc {typ}'; break
                disp = struct.unpack_from('<i', tbytes, off)[0]
                dest = rva + off + 4 + TAIL[typ] + disp
                if syms.setdefault(name, dest) != dest:
                    bad = 'inconsistent reference'; break
            if bad:
                res.update(result='unresolvable', reason=bad)
                results.append(res); continue
            tid = f'{a.tag}-{rva:x}'
            d = out / tid
            d.mkdir(exist_ok=True)
            objb = obj.read_bytes()
            srcrev = sha(a.tag.encode() + b':' + objb)
            task = {'task_id': tid, 'build_id': manifest['build_id'], 'target_image_sha256': manifest['image_sha256'],
                    'recipe_sha256': rsha, 'rva': rva, 'size': size, 'symbol': sym,
                    'source_revision': srcrev, 'source_path': a.tag + '/' + s['key'][0]}
            record = {'source_revision': srcrev, 'source_path': task['source_path'], 'recipe_sha256': rsha,
                      'object_sha256': sha(objb)}
            # the EH personality routine is referenced from unwind data, not from code, so no code relocation names it
            syms.setdefault('__CxxFrameHandler3', FRAME_HANDLER)
            smap = {'schema': 1, 'build_id': manifest['build_id'],
                    'symbols': {n: {'rva': v, 'size': None} for n, v in syms.items()}}
            for n, v in (d / 'task.json', task), (d / 'record.json', record), (d / 'symbols.json', smap):
                n.write_text(json.dumps(v))
            p = subprocess.run([sys.executable, str(REPO / 'tools/compare_runtime.py'),
                                '--task', str(d / 'task.json'), '--recipe', str(recipe), '--build-record', str(d / 'record.json'),
                                '--object', str(obj), '--image', str(img), '--symbols', str(d / 'symbols.json'),
                                '--report', str(d / 'report.json'), '--diagnostics', str(d / 'diag.json')],
                               capture_output=True, text=True)
            if (d / 'report.json').exists():
                r = json.loads((d / 'report.json').read_text())
                res.update(result=r['result'], reason=r['reason'])
            else:
                res.update(result='error', reason=p.stderr.strip()[-200:])
        except Exception as e:  # noqa: BLE001
            res.update(result='error', reason=str(e)[:200])
        results.append(res)
    json.dump(results, open(out / 'results.json', 'w'), indent=1)
    import collections
    print(collections.Counter((r['result'], r.get('reason')) for r in results))


def pe_off(data, rva):
    from shape import pe_sections
    base, secs = pe_sections(data[:4096 * 4])
    for va, sz, ptr in secs:
        if va <= rva < va + sz:
            return ptr + rva - va
    raise ValueError('rva outside sections')


if __name__ == '__main__':
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    main()
