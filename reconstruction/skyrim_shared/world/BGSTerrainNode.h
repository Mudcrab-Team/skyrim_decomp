// Source exposure: mixed (community declarations and the contributor-owned pack).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original reconstruction from the pinned image listing; class names and member
// layout from the pinned community headers, marked with labels below. No game bytes are stored here.
// BGSTerrainNode, manager, chunkHandle, blockHandle, treeHandle, mapChunkHandle, mapBlockHandle, children, parent, nodeState, nodeNumber, baseCellX, baseCellY: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IsWithinObjectLevel0Distance, IsWithinObjectLevel1Distance, UnloadDataRecurse, UnloadData, Function51a6e0, unknown4C, objectLevel0Distance, objectLevel1Distance: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// The pinned community header gives these handle fields opaque handle types. The reconstruction has
// no header for them, so each is stored as a same-size integer without claiming its type.
extern float objectLevel0Distance;
extern float objectLevel1Distance;

// Callee at RVA 0x51a6e0. The listing gives no name and no signature beyond a float result.
float Function51a6e0();

class BGSTerrainNode
{
public:
    bool IsWithinObjectLevel0Distance() const;
    bool IsWithinObjectLevel1Distance() const;

    // UnloadData: GUESS(low); name only, the listing shows a member call with this in RCX and the
    // flags in EDX.
    void UnloadData(std::uint32_t flags);
    void UnloadDataRecurse(std::uint32_t flags);

    void* manager;                // 00
    std::uint64_t chunkHandle;    // 08
    std::uint64_t blockHandle;    // 10
    std::uint64_t treeHandle;     // 18
    std::uint64_t mapChunkHandle; // 20
    std::uint64_t mapBlockHandle; // 28
    BGSTerrainNode* children;     // 30
    BGSTerrainNode* parent;       // 38
    std::uint32_t nodeState;      // 40
    std::uint32_t nodeNumber;     // 44
    std::int16_t baseCellX;       // 48
    std::int16_t baseCellY;       // 4A
    // The 4-byte field at 0x4C is unread by this function's pack, so its meaning is unknown.
    std::uint32_t unknown4C;      // 4C
};
static_assert(sizeof(BGSTerrainNode) == 0x50, "BGSTerrainNode size");
static_assert(offsetof(BGSTerrainNode, children) == 0x30, "children offset");
static_assert(offsetof(BGSTerrainNode, nodeState) == 0x40, "nodeState offset");
static_assert(offsetof(BGSTerrainNode, baseCellY) == 0x4A, "baseCellY offset");
