"""Rendering inventory: a synthetic repository tree, no game data."""
import json
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools')]
import render_inventory as inv_tool

PDB = 'reconstruction/generated/crashlogger_pdb'


def write(root, rel, text):
    path = Path(root) / rel
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text if isinstance(text, str) else json.dumps(text), encoding='utf-8')


def fixture(root):
    names = {0x1000: 'BSLightingShader::ctor', 0x1100: 'BSLightingShader::Dtor', 0x1200: 'BSBatchRenderer::Draw',
             0x1300: 'BSGraphics::Renderer::Init', 0x1400: 'Renderer::Lock', 0x1500: 'ShadowSceneNode::Update',
             0x1600: 'Actor::Update'}
    sizes = {0x1000: 8, 0x1100: 120, 0x1200: 30, 0x1300: 200, 0x1400: 14, 0x1500: 40, 0x1600: 50}
    write(root, f'{PDB}/names/00.tsv', '# label\n' + ''.join(f'0x{r:x}\t{n}\n' for r, n in names.items()))
    write(root, f'{PDB}/boundaries/00.tsv', '# label\n' + ''.join(f'{r:x}\t{s:x}\n' for r, s in sizes.items()))
    write(root, 'data/progress.json', {
        'target_build_id': 'b1', 'updated_at': 'stamp',
        'functions': [
            {'rva': 0x1000, 'size': 8, 'status': 'matched', 'name': 'BSLightingShader::ctor'},
            {'rva': 0x1500, 'size': 40, 'status': 'mapped', 'name': 'ShadowSceneNode::Update'},
            {'rva': 0x1700, 'size': 12, 'status': 'mapped', 'name': 'BSImagespaceShaderBlur3::Func'},
        ]})
    write(root, 'data/ready-queue.json', {
        'progress_updated_at': 'queue-stamp',
        'counts': {'ready': 10, 'listed': 2},
        'entries': [{'rva': '0x1400', 'size': 14, 'blocks': 3, 'unlocks': 0},
                    {'rva': '0x1200', 'size': 30, 'blocks': 1, 'unlocks': 0}]})
    write(root, 'data/symbol-names.json', {'classes': {'BSLightingShader': {'candidates': {'A': 'a', 'B': 'b'}}}})
    write(root, 'data/giveups/b1/1100.json', {'rva': '0x1100', 'records': [{'category': 'control-flow'}]})
    write(root, 'reconstruction/INDEX.md', '| `bsshader/BSLightingShader` | `X` (GUESS) | `b1` / `0x1000` / 8 | r | rec | '
                                           'matched | full | - |\n')


class Naming(unittest.TestCase):
    def test_clean_strips_templates_thunk_prefix_and_address_suffix(self):
        self.assertEqual(inv_tool.clean('thunk_BSTArray<Foo<int>>::Push'), 'BSTArray::Push')
        self.assertEqual(inv_tool.clean('Foo_Bar_140d6a6d0'), 'Foo_Bar')

    def test_renderer_spellings_share_one_class(self):
        for name in ('Renderer::Lock', 'BSGraphics::Renderer::Lock', 'BSGraphics::Renderer_Lock',
                     'BSGraphics_Renderer_SetClearColors'):
            self.assertEqual(inv_tool.class_key(name), 'BSGraphics::Renderer')

    def test_group_of_prefers_the_first_matching_group(self):
        self.assertEqual(inv_tool.group_of('BSShaderProperty::RenderPassArray::Grow')[0], 'C1')
        self.assertEqual(inv_tool.group_of('BSShaderProperty::SetupGeometry')[0], 'B2')
        self.assertEqual(inv_tool.group_of('BSImagespaceShaderISSAORawAO::Foo')[0], 'D2')
        self.assertIsNone(inv_tool.group_of('Actor::Update'))
        self.assertIsNone(inv_tool.group_of('BSLightingShaderPropertyX::Foo'))

    def test_every_group_has_a_known_workstream(self):
        self.assertTrue({g[1] for g in inv_tool.GROUPS} <= set(inv_tool.WORKSTREAMS))
        self.assertEqual(len({g[0] for g in inv_tool.GROUPS}), len(inv_tool.GROUPS))


class Counting(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        fixture(self.root)

    def tearDown(self):
        self.tmp.cleanup()

    def states(self, claims=None):
        inv = inv_tool.build(self.root, claims)
        return {r['rva']: (r['group'], r['status'], r.get('state')) for r in inv['rows']}, inv

    def test_states_follow_matched_ready_giveup_and_cap(self):
        rows, inv = self.states()
        self.assertEqual(rows[0x1000], ('B1', 'matched', None))
        self.assertEqual(rows[0x1100], ('B1', 'open', 'blocked'))
        self.assertEqual(rows[0x1200], ('C1', 'open', 'ready'))
        self.assertEqual(rows[0x1300], ('A1', 'open', 'unlisted'))
        self.assertEqual(rows[0x1400], ('A1', 'open', 'ready'))
        self.assertEqual(rows[0x1500], ('D1', 'open', 'unlisted'))
        self.assertEqual(rows[0x1700], ('D2', 'open', 'blocked'))
        self.assertNotIn(0x1600, rows)
        self.assertEqual(inv['complete_below'], 16)

    def test_small_unlisted_function_below_the_complete_part_is_waiting(self):
        rows, _ = self.states()
        self.assertEqual(rows[0x1700][2], 'blocked')

    def test_open_claim_takes_a_function_out_of_ready(self):
        rows, inv = self.states([{'number': 7, 'entries': [[0x1400, 0x1401]]}])
        self.assertEqual(rows[0x1400][2], 'claimed')
        self.assertEqual(inv['claim_count'], 1)
        self.assertEqual(inv_tool.entry_points(inv, 'A', 5)[0]['rva'], 0x1300)

    def test_summary_columns_add_up(self):
        _, inv = self.states()
        groups, _ = inv_tool.summarize(inv)
        for cell in groups.values():
            parts = cell['matched'] + cell['claimed'] + cell['ready'] + cell['blocked'] + cell['unlisted']
            self.assertEqual(parts, cell['known'])

    def test_class_report_carries_unplaced_sibling_names(self):
        _, inv = self.states()
        self.assertEqual(inv_tool.unplaced(inv, 'BSLightingShader'), 2)
        self.assertEqual(inv_tool.unplaced(inv, 'BSBatchRenderer'), 0)

    def test_unit_area_comes_from_the_index(self):
        _, inv = self.states()
        self.assertEqual(inv['areas'][0x1000], 'bsshader')

    def test_complete_ready_list_leaves_nothing_unlisted(self):
        queue = json.loads((self.root / 'data/ready-queue.json').read_text())
        queue['counts']['ready'] = 2
        write(self.root, 'data/ready-queue.json', queue)
        rows, inv = self.states()
        self.assertIsNone(inv['complete_below'])
        self.assertEqual(rows[0x1300][2], 'blocked')


class Output(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name)
        fixture(self.root)

    def tearDown(self):
        self.tmp.cleanup()

    def test_report_names_the_workstreams_and_the_ready_function(self):
        text = inv_tool.render(inv_tool.build(self.root))
        self.assertIn('| A: Foundation |', text)
        self.assertIn('`0x1400` | Renderer::Lock', text)
        self.assertIn('no claim list was read', text)

    def test_update_doc_replaces_only_the_marked_block(self):
        doc = self.root / 'doc.md'
        doc.write_text(f'before\n{inv_tool.BLOCK_START}\nold\n{inv_tool.BLOCK_END}\nafter\n', encoding='utf-8')
        out = self.root / 'unused.json'
        self.assertEqual(inv_tool.main(['--root', str(self.root), '--update-doc', str(doc)]), 0)
        text = doc.read_text(encoding='utf-8')
        self.assertTrue(text.startswith('before\n') and text.endswith('after\n'))
        self.assertNotIn('\nold\n', text)
        self.assertIn('Workstream', text)
        self.assertFalse(out.exists())

    def test_update_doc_without_markers_is_refused(self):
        doc = self.root / 'doc.md'
        doc.write_text('no markers\n', encoding='utf-8')
        with self.assertRaises(SystemExit):
            inv_tool.main(['--root', str(self.root), '--update-doc', str(doc)])

    def test_json_output_lists_rows(self):
        out = self.root / 'inv.json'
        inv_tool.main(['--root', str(self.root), '--json', str(out)])
        doc = json.loads(out.read_text())
        self.assertEqual({r['rva'] for r in doc['rows']}, {0x1000, 0x1100, 0x1200, 0x1300, 0x1400, 0x1500, 0x1700})


if __name__ == '__main__':
    unittest.main()
