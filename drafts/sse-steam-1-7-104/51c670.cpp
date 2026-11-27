// Near miss: 10.5 alignment distance | control-flow
// Source exposure: mixed
// Code origin: adapted from the cited permitted sibling body, with target-specific reconstruction.
// 0x51c670 BGSQueuedTerrainInitialLoad::CheckPreconditions
// BGSQueuedTerrainInitialLoad, CheckPreconditions: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUpdateManager.cpp:241
// Body adapted with target-specific child layout and cancellation checks.
// TestBit: GUESS(low); indexed accessor written from cookbook rule 16.
#include "include/51c670/BGSQueuedTerrainInitialLoad_51c670.h"

inline bool TestBit(std::uint32_t state, unsigned int bit)
{
    return ((state >> bit) & 1) != 0;
}

// GetChild: GUESS(low); inline array accessor reconstructed from target indexing.
inline BGSTerrainNode* BGSTerrainNode::GetChild(unsigned int index)
{
    return pChildren ? &pChildren[index] : nullptr;
}

bool BGSQueuedTerrainInitialLoad::CheckPreconditions()
{
    if (!TestBit(pNode->parent->nodeState, 2)) {
        for (unsigned int i = 0; i < 4; ++i) {
            BGSTerrainNode* child = pNode->GetChild(i);
            if (child && !TestBit(child->nodeState, 1))
                return false;
        }
        return true;
    }
    return false;
}
