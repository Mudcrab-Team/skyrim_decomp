// Exposure detail: (community declarations; community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; labelled declarations and pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// NiNode, NiNode::FindAddonAttachPoint, NiRTTI: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNodeVTable, NiAVObjectPrefix, objectState, addonType: STANDIN OBSERVED

#pragma once
#include <cstdint>
#include <cstddef>
struct NiNode;
struct NiAVObjectPrefix;
struct NiRTTI { const char* name; const NiRTTI* baseRTTI; };
extern const NiRTTI addonType;
struct NiNodeVTable
{
    void* refObjectSlots[2];
    const NiRTTI* (*getRTTI)(NiAVObjectPrefix*);
    NiNode* (*asNode)(NiAVObjectPrefix*);
    void* intermediateSlots[54];
    void (*detachChildAt)(NiNode*, std::uint32_t);
};
struct NiAVObjectPrefix
{
    NiNodeVTable* vtable;
    std::uint8_t objectState[0x108];
};
struct NiNode : NiAVObjectPrefix
{
    static void FindAddonAttachPoint(NiNode* root);
    void* childrenVTable;
    NiAVObjectPrefix** children;
    std::uint16_t capacity;
    std::uint16_t freeIndex;
    std::uint16_t size;
    std::uint16_t growBy;
};
static_assert(offsetof(NiNode, children) == 0x118, "children data offset");
static_assert(offsetof(NiNode, freeIndex) == 0x122, "children limit offset");
