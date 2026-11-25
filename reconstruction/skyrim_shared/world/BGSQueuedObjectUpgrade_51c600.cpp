// Origin check: TestBit is independently written from cookbook rule 16; this incidental similarity is not reused.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Source exposure: mixed
// Code origin: adapted from the cited permitted sibling body, with target-specific reconstruction.
// 0x51c600 BGSQueuedObjectUpgrade::CheckPreconditions
// BGSQueuedObjectUpgrade, CheckPreconditions: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUpdateManager.cpp:314
// Body adapted with target-specific child layout and cancellation checks.
// pChildren: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); name only.
// TestBit: GUESS(low); indexed accessor written from cookbook rule 16.
#include "BGSQueuedObjectUpgrade_51c600.h"

inline bool TestBit(std::uint32_t state, unsigned int bit)
{
    return ((state >> bit) & 1) != 0;
}

bool BGSQueuedObjectUpgrade::CheckPreconditions()
{
    if (!TestBit(pNode->nodeState, 7))
        return false;
    BGSTerrainNode* children = pNode->pChildren;
    for (unsigned int i = 0; i < 4; ++i) {
        BGSTerrainNode* child = children ? &children[i] : nullptr;
        if ((child->nodeState & 0x120) == 0)
            return false;
    }
    if (bCancelled)
        return false;
    return true;
}
