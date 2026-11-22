import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tools'))
import unit_paths  # noqa: E402


class PdbClassPlacementTests(unittest.TestCase):
    def place(self, cls):
        return unit_paths.unit_dir(cls, ROOT)

    def test_classes_known_from_pdb_layouts_have_an_area(self):
        for cls, area in {
            'SkyrimVM': 'bsscript', 'VirtualMachine': 'bsscript', 'Stack': 'bsscript', 'Object': 'bsscript',
            'Pathing': 'skyrim_shared/pathfinding', 'PathingLockData': 'skyrim_shared/pathfinding',
            'NavMeshObstacleManager': 'skyrim_shared/pathfinding', 'PathFollowerStateTurnToAngle': 'skyrim_shared/pathfinding',
            'BSStream': 'bssystem', 'QueuedReference': 'bssystem', 'Win32FileType': 'bssystem',
            'BShkbAnimationGraph': 'gamebryo/nianimation', 'BSLagBoneController': 'gamebryo/nianimation',
            'BSLimbIKModifierUtility': 'gamebryo/nianimation', 'BSLookIKNote': 'gamebryo/nianimation',
            'BSLODTriShape': 'gamebryo/nimain', 'BSTreeNode': 'gamebryo/nimain', 'BSBoneLODExtraData': 'gamebryo/nimain',
            'Results': 'gamebryo/nimain', 'BSStripPSysData': 'gamebryo/niparticle',
            'ShadowSceneNode': 'bsshader', 'BSBatchRenderer': 'bsshader', 'Renderer': 'bsshader',
            'ImageSpaceEffectGetHit': 'bsshader', 'Sun': 'skyrim_shared/sky', 'Clouds': 'skyrim_shared/sky',
            'PlayerControls': 'skyrim/controls', 'HUDMeter': 'skyrim/interface', 'UI_Text2': 'skyrim/interface',
            'UISaveLoadManager': 'skyrim/interface', 'InventoryEntryData': 'skyrim_shared/inventory',
            'ObjectInterface': 'thirdparty/scaleform', 'GString': 'thirdparty/scaleform',
            'LoadTaskData': 'thirdparty/scaleform', 'ScrapHeap': 'bscore', 'BSTArray': 'bscore',
            'GameSettingCollection': 'bsmain', 'KinectEvent': 'bsinput', 'ButtonEvent': 'bsinput',
            'Effect': 'skyrim_shared/magic', 'TypeData': 'skyrim/ai/movement', 'Transition': 'skyrim/camera',
            'PlayerRegionState': 'skyrim_shared/world',
        }.items():
            self.assertEqual(self.place(cls), area, cls)

    def test_ambiguous_names_stay_unplaced(self):
        for cls in ('Mutex', 'Entry', 'Event', 'Sound', 'GarbageCollector', 'DebugText', 'JobList', 'StateInfo'):
            self.assertIsNone(self.place(cls), cls)

    def test_classes_placed_before_the_pdb_rules_keep_their_area(self):
        for cls, area in {
            'BSShaderAccumulator': 'bsshader', 'BSLightingShaderProperty': 'bsshader',
            'SkyrimVMInterface': 'bsscript', 'QueuedPromoteReferencesTask': 'bssystem',
            'BSPathingRequest': 'skyrim_shared/pathfinding', 'BSScaleformTranslator': 'bsscaleform',
            'BSExtraData': 'skyrim_shared/extradata', 'BSTriShape': 'gamebryo/nimain',
            'BSWindModifier': 'gamebryo/nianimation', 'BSTempEffect': 'skyrim_shared/tempeffects',
            'ImageSpaceModifierInstance': 'skyrim_shared/world', 'Actor': 'skyrim_shared/actors',
        }.items():
            self.assertEqual(self.place(cls), area, cls)

    def test_every_area_a_rule_or_override_names_is_known(self):
        for _pattern, area in unit_paths.RULES:
            self.assertIn(area, unit_paths.AREAS)
        for area in unit_paths.overrides(ROOT).values():
            self.assertIn(area, unit_paths.AREAS)


if __name__ == '__main__':
    unittest.main()
