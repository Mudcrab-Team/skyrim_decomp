// Code origin: adapted child-state walk with locally observed null handling.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainUpdateManager.cpp:411
// Exposure detail: (local binary analysis and permitted sibling declarations).
// Source exposure: mixed
// BGSQueuedObjectInitialLoad: EXE_RTTI
// BGSTerrainNode, BGSTerrainNode::pParent, BGSTerrainNode::pChildren, BGSTerrainNode::uiNodeState, BGSTerrainNode::QChild, CheckPreconditions: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// pNode: STANDIN SIBLING(fo4-private@1b765c70, author-permission); inherited from BGSQueuedTerrainUpdate.
// ChildrenReady: GUESS(low); child-state readiness predicate.
// unk00, unk44, TestBit: GUESS(low); unaccessed storage and by-value flag helper.

#pragma once
#include <cstddef>
#include <cstdint>

struct BGSTerrainNode
{
    BGSTerrainNode* QChild(std::uint32_t index)
    {
        return pChildren ? &pChildren[index] : nullptr;
    }
    bool ChildrenReady()
    {
        if (!pChildren)
            return true;
        for (std::uint32_t i = 0; i < 4; ++i) {
            BGSTerrainNode* child = QChild(i);
            if (!child)
                return true;
            if ((child->uiNodeState & 0x120u) == 0)
                return false;
        }
        return true;
    }
    std::uint8_t unk00[0x30];
    BGSTerrainNode* pChildren;
    BGSTerrainNode* pParent;
    std::uint32_t uiNodeState;
    std::uint8_t unk44[0xC];
};

inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1u) != 0;
}

class BGSQueuedObjectInitialLoad
{
public:
    bool CheckPreconditions();
    std::uint8_t unk00[8];
    BGSTerrainNode* pNode;
};
static_assert(sizeof(BGSTerrainNode) == 0x50, "terrain node stride");
static_assert(offsetof(BGSTerrainNode, pChildren) == 0x30, "children offset");
static_assert(offsetof(BGSTerrainNode, pParent) == 0x38, "parent offset");
static_assert(offsetof(BGSTerrainNode, uiNodeState) == 0x40, "node state offset");
static_assert(offsetof(BGSQueuedObjectInitialLoad, pNode) == 8, "node pointer offset");
