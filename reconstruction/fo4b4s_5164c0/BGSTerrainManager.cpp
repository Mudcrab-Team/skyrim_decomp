// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// BGSTerrainManager::GetLODLandRootForLevel: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// names: GUESS(low); names and original signatures are tentative.
// 0x5164c0 BGSTerrainManager::GetLODLandRootForLevel
#include "BGSTerrainManager.h"
NiNode* BGSTerrainManager::GetLODLandRootForLevel(unsigned level) { switch(level) { case 4: return roots[0]; case 8: return roots[1]; case 16: return roots[2]; } NiNode* node = roots[3]; if (level != 32) return nullptr; return node; }
