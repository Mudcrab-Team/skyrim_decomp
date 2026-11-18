"""tools/mapping_check.py: the mapping-only PR gate, on real git history in a temporary repository."""
import copy
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import mapping_check  # noqa: E402

BUILD = 'sse-steam-1-7-104'


def entry(rva, size=16, **kw):
    fn = dict(build_id=BUILD, evidence='findings/old.md', id=f'{BUILD}-0x{rva:x}', name=f'Klass::Fn{rva:x}',
              name_origin='COMMUNITY', name_source='Community name, not verified: pinned header.', owner='someone',
              rva=rva, size=size, status='mapped')
    fn.update(kw)
    return fn


def matched(rva, size=16):
    return dict(entry(rva, size), status='matched', report=f'reports/{BUILD}/0x{rva:x}.json', named=False)


class Repo:
    def __init__(self, root):
        self.root = Path(root)
        self.git('init', '-q', '-b', 'main')
        self.base = {'functions': [matched(0x1000), entry(0x2000)], 'updated_at': 'x', 'phase': 'p'}
        self.write('builds/target.json', json.dumps({'build_id': BUILD}))
        self.write('findings/old.md', 'old\n')
        self.write_progress(self.base)
        self.git('add', '-A')
        self.commit('base')
        self.base_sha = self.rev()

    def git(self, *args):
        return subprocess.run(['git', '-C', str(self.root), '-c', 'user.email=t@t', '-c', 'user.name=t', *args],
                              capture_output=True, text=True, check=True).stdout.strip()

    def rev(self):
        return self.git('rev-parse', 'HEAD')

    def commit(self, message):
        self.git('commit', '-q', '--allow-empty', '-m', message)

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def write_progress(self, doc, canonical=True):
        text = json.dumps(doc, indent=2, ensure_ascii=False) + '\n'
        self.write('data/progress.json', text if canonical else text.replace('\n', '\r\n'))

    def head(self, doc, files=None, canonical=True):
        """Check out a fresh branch from base holding `doc` and `files`; returns its commit."""
        self.git('checkout', '-q', '-B', 'pr', self.base_sha)
        self.write_progress(doc, canonical)
        for name, text in (files or {}).items():
            self.write(name, text)
        self.git('add', '-A')
        self.commit('pr')
        return self.rev()


class MappingCheckTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.repo = Repo(self.tmp.name)

    def codes(self, doc, files=None, main=None, scan=False, canonical=True):
        head = self.repo.head(doc, files, canonical)
        return mapping_check.check(self.repo.root, self.repo.base_sha, head, main, scan)

    def doc(self, *added, **top):
        doc = copy.deepcopy(self.repo.base)
        doc['functions'] += list(added)
        doc.update(top)
        return doc

    def test_a_valid_mapping_with_a_new_findings_file_passes(self):
        added = [entry(0x3000, evidence='findings/new.md'), entry(0x4000, name_origin='GUESS', name_source='GUESS(low): shape.')]
        self.assertEqual(self.codes(self.doc(*added), {'findings/new.md': 'notes\n'}), [])

    def test_the_scan_runs_and_a_dirty_diff_is_refused(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000)), scan=True), [])
        dirty = entry(0x3000, name_source='Community name: FUN_00401000 from /Users/someone/x')
        self.assertEqual(self.codes(self.doc(dirty), scan=True), ['leak'])

    def test_the_shape_is_progress_plus_new_findings_only(self):
        doc = self.doc(entry(0x3000))
        for files in ({'docs/progress.svg': '<svg/>'}, {'reconstruction/INDEX.md': 'x'}, {'tools/x.py': 'x'},
                      {'findings/old.md': 'changed\n'}, {'findings/sub/x.md': 'x'}, {'findings/x.txt': 'x'}):
            self.assertEqual(self.codes(doc, files), ['shape'], files)
        head = self.repo.head(doc)
        self.git_remove('data/progress.json')
        self.assertEqual(mapping_check.check(self.repo.root, self.repo.base_sha, self.repo.rev(), None, False), ['shape'])
        self.assertTrue(head)

    def git_remove(self, name):
        self.repo.git('rm', '-q', name)
        self.repo.commit('rm')

    def test_only_the_functions_list_may_change(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000), updated_at='y')), ['top-level'])
        self.assertEqual(self.codes(self.doc(entry(0x3000), extra=1)), ['top-level'])

    def test_existing_entries_are_never_removed_modified_or_reordered(self):
        removed = self.doc(entry(0x3000))
        removed['functions'].pop(1)
        self.assertEqual(self.codes(removed), ['removed'])
        edited = self.doc(entry(0x3000))
        edited['functions'][1]['name'] = 'Other'
        self.assertEqual(self.codes(edited), ['modified'])
        promoted = self.doc(entry(0x3000))
        promoted['functions'][1]['status'] = 'matched'
        self.assertEqual(self.codes(promoted), ['modified'])
        swapped = self.doc(entry(0x3000))
        swapped['functions'][:2] = swapped['functions'][1::-1]
        self.assertEqual(self.codes(swapped), ['modified'])
        self.assertEqual(self.codes(self.doc()), ['shape'])  # no change at all is not a mapping PR

    def test_added_entries_must_be_mapped_and_carry_no_match_fields(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000, status='matched'))), ['status'])
        self.assertEqual(self.codes(self.doc(entry(0x3000, status='analyzed'))), ['status'])
        self.assertIn('forbidden-field', self.codes(self.doc(entry(0x3000, report='reports/x.json'))))
        self.assertIn('forbidden-field', self.codes(self.doc(entry(0x3000, matched=True))))

    def test_entries_follow_the_existing_schema(self):
        bad = (entry(0x3000, size=0), entry(0x3000, size='4'), entry(0x3000, name=''), entry(0x3000, owner=None),
               entry(0x3000, id='wrong'), entry(0x3000, build_id='other'), entry(0x3000, name_origin='GUESSED'),
               entry(0x3000, named=False), dict(entry(0x3000), rva=True), entry(0x3000, name_source=' '))
        for fn in bad:
            self.assertEqual(self.codes(self.doc(fn)), ['schema'], fn)
        missing = entry(0x3000)
        del missing['owner']
        self.assertEqual(self.codes(self.doc(missing)), ['schema'])

    def test_a_known_rva_or_overlapping_range_is_refused(self):
        self.assertEqual(self.codes(self.doc(entry(0x2000), entry(0x3000))), ['duplicate-rva'])
        self.assertEqual(self.codes(self.doc(entry(0x3000), entry(0x3000))), ['duplicate-rva'])
        self.assertEqual(self.codes(self.doc(entry(0x2008))), ['overlap'])
        self.assertEqual(self.codes(self.doc(entry(0x3000, size=0x20), entry(0x3010))), ['overlap'])

    def test_an_rva_added_to_main_since_the_pr_was_cut_is_refused(self):
        newer = copy.deepcopy(self.repo.base)
        newer['functions'].append(entry(0x3000))
        self.assertEqual(self.codes(self.doc(entry(0x3000)), main=None), [])
        self.repo.git('checkout', '-q', 'main')
        self.repo.write_progress(newer)
        self.repo.git('add', '-A')
        self.repo.commit('main moved')
        tip = self.repo.rev()
        head = self.repo.head(self.doc(entry(0x3000)))
        self.assertEqual(mapping_check.check(self.repo.root, self.repo.base_sha, head, tip, False), ['duplicate-rva'])
        head = self.repo.head(self.doc(entry(0x3008, size=4)))
        self.assertEqual(mapping_check.check(self.repo.root, self.repo.base_sha, head, tip, False), ['overlap'])

    def test_guess_names_carry_a_label(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000, name_origin='GUESS', name_source='probably a vtable'))),
                         ['guess-label'])
        self.assertEqual(self.codes(self.doc(entry(0x3000, name_origin='GUESS', name_source='GUESS(low): shape'))), [])
        self.assertEqual(self.codes(self.doc(entry(0x3000, name_source='This is a GUESS'))), ['guess-label'])

    def test_evidence_must_be_an_existing_findings_file(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000, evidence='findings/missing.md'))), ['evidence'])
        self.assertEqual(self.codes(self.doc(entry(0x3000, evidence='reports/x/y.json'))), ['evidence'])
        self.assertEqual(self.codes(self.doc(entry(0x3000, evidence='findings/../old.md'))), ['evidence'])

    def test_a_reformatted_file_is_refused(self):
        self.assertEqual(self.codes(self.doc(entry(0x3000)), canonical=False), ['json'])

    def test_workflow_shape_filter_agrees_with_the_python_shape(self):
        """The awk that picks the lane in both workflows must accept exactly what shape() accepts."""
        text = (ROOT / '.github/workflows/pr-check.yml').read_text()
        start = text.index("awk -F'\\t' '", text.index('id: shape'))
        program = text[start:text.index("}')", start) + 2].replace("awk -F'\\t' '", '', 1).rstrip("'")
        cases = [[('M', 'data/progress.json')], [('M', 'data/progress.json'), ('A', 'findings/a.md')],
                 [('M', 'data/progress.json'), ('A', 'docs/progress.svg')], [('A', 'findings/a.md')],
                 [('M', 'data/progress.json'), ('M', 'findings/a.md')], [('M', 'data/progress.json'), ('A', 'findings/b/a.md')]]
        for changes in cases:
            listing = ''.join(f'{s}\t{p}\n' for s, p in changes)
            out = subprocess.run(['awk', '-F\t', program], input=listing, capture_output=True, text=True).stdout.strip()
            self.assertEqual(out == 'true', mapping_check.shape(changes), changes)


if __name__ == '__main__':
    unittest.main()
