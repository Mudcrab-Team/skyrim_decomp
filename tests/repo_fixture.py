"""Synthetic repository with an inventory, two units, match records and an origin remote."""
import json
import os
from pathlib import Path
import shutil
import stat
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from digest_v2 import tu_digest  # noqa: E402

BUILD = 'synthetic-build'
FUNCS = [(0x1000, 16, 'Foo::A'), (0x1010, 8, 'Foo::B'), (0x2000, 12, 'Bar::C')]

STUB_ACCEPT = r'''
import json, sys, subprocess
from pathlib import Path
if '--review-batch' in sys.argv:
    requests = json.loads(Path(sys.argv[sys.argv.index('--review-batch') + 1]).read_text())
    for request in requests:
        subprocess.run([sys.executable, __file__, '--review', request['review'],
                        '--functions', *request['functions']], check=True)
    raise SystemExit(0)
review = sys.argv[sys.argv.index('--review') + 1]
data = json.loads(Path('data/progress.json').read_text())
changed = ['data/progress.json']
text = Path(review).read_text()
for fn in data['functions']:
    block = f"## {fn['build_id']} 0x{fn['rva']:x} {fn['size']}\n\nverdict: approve"
    selection = sys.argv[sys.argv.index('--functions') + 1:] if '--functions' in sys.argv else None
    if block in text and (selection is None or f'0x{fn["rva"]:x}' in selection):
        fn['status'] = 'matched'
        rec = Path(f"reports/{fn['build_id']}/0x{fn['rva']:x}.review.json")
        rec.write_text(json.dumps({'verdict': 'approve'}) + '\n')
        changed.append(rec.as_posix())
Path('data/progress.json').write_text(json.dumps(data, indent=2) + '\n')
Path('reconstruction/INDEX.md').write_text(Path('data/progress.json').read_text())
print('accepted')
print('changed files (stage these by name; nothing was committed):')
for c in changed:
    print('  ' + c)
'''


def kept_environment():
    """What an environment cleared for a test must still hold: nothing on POSIX, the system variables on Windows.

    Without them a child process on Windows cannot find git or the system libraries.
    """
    if os.name != 'nt':
        return {}
    names = ('PATH', 'PATHEXT', 'SYSTEMROOT', 'SYSTEMDRIVE', 'COMSPEC', 'WINDIR', 'TEMP', 'TMP', 'USERPROFILE',
             'HOMEDRIVE', 'HOMEPATH', 'LOCALAPPDATA', 'APPDATA', 'PROGRAMDATA', 'PROGRAMFILES')
    return {k: v for k, v in os.environ.items() if k.upper() in names}


def rmtree(path):
    """shutil.rmtree that also removes the read-only object files git leaves behind on Windows."""
    for directory, _, names in os.walk(path):
        for name in names:
            full = os.path.join(directory, name)
            if not os.path.islink(full):
                os.chmod(full, stat.S_IWRITE | stat.S_IREAD)
    shutil.rmtree(path)


def git(cwd, *args):
    return subprocess.run(['git', *args], cwd=cwd, check=True, capture_output=True, text=True).stdout.strip()


class Repo:
    """A tiny repository with an inventory, two units, match records and an origin remote."""

    def __init__(self, tmp, confirmed=(0x1000, 0x1010, 0x2000)):
        self.tmp = tmp
        self.root = tmp / 'repo'
        self.origin = tmp / 'origin.git'
        r = self.root
        (r / 'reconstruction/x').mkdir(parents=True)
        (r / 'reconstruction/x/Foo.cpp').write_text('int a;\n', newline='\n')
        (r / 'reconstruction/x/Foo.h').write_text('#pragma once\n', newline='\n')
        (r / 'reconstruction/x/Bar.cpp').write_text('int c;\n', newline='\n')
        (r / 'reports' / BUILD).mkdir(parents=True)
        (r / 'docs').mkdir()
        (r / 'docs/verification.md').write_text('Reviewer subagent, Opus class.\n', newline='\n')
        (r / 'tools').mkdir()
        (r / 'tools/accept_function.py').write_text(STUB_ACCEPT, newline='\n')
        for name in ('check.py', 'build_site.py'):
            (r / 'tools' / name).write_text('import sys\nsys.exit(0)\n', newline='\n')
        (r / 'tools/build_leaderboard.py').write_text("from pathlib import Path\nfor p in ('LEADERBOARD.md', 'data/contributors.json'):\n Path(p).write_text(Path('data/progress.json').read_text())\n", newline='\n')
        (r / 'tools/build_index.py').write_text("from pathlib import Path\nPath('reconstruction/INDEX.md').write_text(Path('data/progress.json').read_text())\n", newline='\n')
        (r / 'tools/build_progress_svg.py').write_text("from pathlib import Path\nfor p in ('docs/progress.svg', 'docs/progress-map.svg'):\n Path(p).write_text(Path('data/progress.json').read_text())\n", newline='\n')
        (r / 'tools/build_model_trend.py').write_text("from pathlib import Path\nfor p in ('README.md', 'docs/model-trend.svg', 'docs/progress-trend.svg'):\n Path(p).write_text(Path('data/progress.json').read_text())\n", newline='\n')
        (r / 'tools/check.py').write_text("import subprocess, sys\nif '--staged' in sys.argv:\n data = subprocess.check_output(['git', 'show', ':data/progress.json'])\n for p in ('reconstruction/INDEX.md', 'docs/progress.svg', 'docs/progress-map.svg', 'README.md', 'docs/model-trend.svg', 'docs/progress-trend.svg'):\n  assert subprocess.check_output(['git', 'show', ':' + p]) == data\n", newline='\n')
        (r / 'tests').mkdir()
        (r / 'tests/test_ok.py').write_text('import unittest\nclass T(unittest.TestCase):\n    def test(self):\n        pass\n', newline='\n')
        (r / '.gitignore').write_text('.local/\n', newline='\n')
        fns = []
        for rva, size, name in FUNCS:
            fn = {'id': f'{BUILD}-0x{rva:x}', 'build_id': BUILD, 'rva': rva, 'size': size, 'status': 'mapped', 'name': name}
            if rva in confirmed:
                unit = ['reconstruction/x/Foo.cpp', 'reconstruction/x/Foo.h'] if rva < 0x2000 else ['reconstruction/x/Bar.cpp']
                rec = {'source': {'compiled': unit[0], 'translation_unit': unit, 'digest': tu_digest(r, unit)},
                       'recipe': {'sha256': 'r' * 64}, 'toolchain_pin': {'sha256': 't' * 64},
                       'runs': [{'compiled_on': 'host-a'}, {'compiled_on': 'host-b'}]}
                (r / f'reports/{BUILD}/0x{rva:x}.json').write_text(json.dumps(rec), newline='\n')
                fn['report'] = f'reports/{BUILD}/0x{rva:x}.json'
            fns.append(fn)
        (r / 'data').mkdir()
        (r / 'data/progress.json').write_text(json.dumps({'target_build_id': BUILD, 'functions': fns}, indent=2) + '\n', newline='\n')
        git(tmp, 'init', '--quiet', '--bare', str(self.origin))
        git(r, 'init', '--quiet', '-b', 'main')
        # The fixture's sources are LF, as the repository's attributes make them; keep git from rewriting them.
        git(r, 'config', 'core.autocrlf', 'false')
        git(r, 'config', 'user.email', 't@example.invalid')
        git(r, 'config', 'user.name', 'test')
        git(r, 'add', '-A')
        git(r, 'commit', '--quiet', '-m', 'base')
        git(r, 'remote', 'add', 'origin', str(self.origin))
        git(r, 'push', '--quiet', 'origin', 'main')
        self.fdir = r / '.local/flow'

    def digest(self, rva):
        return json.loads((self.root / f'reports/{BUILD}/0x{rva:x}.json').read_text())['source']['digest']
