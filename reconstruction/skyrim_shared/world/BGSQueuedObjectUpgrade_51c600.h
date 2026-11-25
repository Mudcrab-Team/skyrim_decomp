// Source exposure: mixed
// Code origin: original partial declarations with source-derived names as labelled below.
// BGSTerrainNode, parent, nodeState: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// pChildren: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); name only, target-specific array view.
// TestBit: GUESS(low); indexed flag accessor.
// pNode, bCancelled: GUESS(low); queued node and cancellation flag from observed accesses.
// BGSQueuedObjectUpgrade, CheckPreconditions: SIBLING(fo4-private@1b765c70, author-permission)
// 0x51c600 BGSQueuedObjectUpgrade::CheckPreconditions
#pragma once
#include <cstddef>
#include <cstdint>

class BGSTerrainNode
{
public:
    unsigned char unk00[0x30];
    BGSTerrainNode* pChildren;
    BGSTerrainNode* parent;
    std::uint32_t nodeState;
    unsigned char unk44[0x0C];
};
static_assert(sizeof(BGSTerrainNode) == 0x50, "terrain node stride");
static_assert(offsetof(BGSTerrainNode, pChildren) == 0x30, "child array offset");
static_assert(offsetof(BGSTerrainNode, parent) == 0x38, "parent offset");
static_assert(offsetof(BGSTerrainNode, nodeState) == 0x40, "node state offset");

class BGSQueuedObjectUpgrade
{
public:
    bool CheckPreconditions();
    void* unk00;
    BGSTerrainNode* pNode;
    std::uint32_t unk10;
    bool bCancelled;
};
static_assert(offsetof(BGSQueuedObjectUpgrade, pNode) == 8, "queued node offset");
static_assert(offsetof(BGSQueuedObjectUpgrade, bCancelled) == 0x14, "cancel flag offset");
