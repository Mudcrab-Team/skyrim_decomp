// Near miss: 9.0 alignment distance | control-flow
// Exposure detail: (local binary analysis and permitted sibling source).
// Source exposure: mixed
// Code origin: adapted CheckPreconditions with target-specific child null handling.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUpdateManager.cpp:411
// BGSQueuedObjectInitialLoad: EXE_RTTI
// CheckPreconditions: SIBLING(fo4-private@1b765c70, author-permission)
// Cookbook: 16
// 0x51c5b0 BGSQueuedObjectInitialLoad::CheckPreconditions

#include "include/51c5b0/BGSQueuedObjectInitialLoad_51c5b0.h"

bool BGSQueuedObjectInitialLoad::CheckPreconditions()
{
    BGSTerrainNode* parent = pNode->pParent;
    if (parent && TestBit(parent->uiNodeState, 7))
        return false;
    return pNode->ChildrenReady();
}
