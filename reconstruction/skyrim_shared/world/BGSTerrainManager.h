// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// BGSTerrainManager::GetLODLandRootForLevel: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// names: GUESS(low); names and original signatures are tentative.
#pragma once
class NiNode;
class BGSTerrainManager { public: static NiNode* roots[4]; static NiNode* GetLODLandRootForLevel(unsigned level); };
