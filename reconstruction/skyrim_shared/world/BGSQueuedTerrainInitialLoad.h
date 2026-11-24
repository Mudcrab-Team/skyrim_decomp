// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf and original reconstruction of Function51c570, kept unchanged;
// Function51ada0 is independently decoded from the pinned image listing, a fresh reconstruction
// from the observed instruction shapes, with no copied community body.
// Adapted bodies: none.
// BGSQueuedTerrainInitialLoad: EXE_RTTI
// Function51c570, ReleaseQueuedTerrain: GUESS(low)
// SPDX-License-Identifier: CC0-1.0
#pragma once
#include <cstddef>
#include <cstdint>

void ReleaseQueuedTerrain(void* a_target);

// QueuedLoadNode: GUESS(low); node type of the queued-load chain reached through the object
// at offset 0x08, from the field offsets the listing reads.
struct QueuedLoadNode
{
    // vtable: GUESS(low); vtable pointer at 0x00, not read by this function.
    void* vtable;
    // unknown08: GUESS(low); slot at 0x08 that the function compares and overwrites.
    QueuedLoadNode* unknown08;
    // unknown10: GUESS(low); meaning unknown.
    void* unknown10;
    // unknown18: GUESS(low); meaning unknown.
    void* unknown18;
    // unknown20: GUESS(low); meaning unknown.
    void* unknown20;
    // unknown28: GUESS(low); pointer handed to the first callee.
    void* unknown28;
    // unknown30: GUESS(low); meaning unknown.
    void* unknown30;
    // unknown38: GUESS(low); next node of the chain walked by the function.
    QueuedLoadNode* unknown38;
    // flags: GUESS(low); flag word at 0x40 whose bits 1 to 4 the function updates.
    std::uint32_t flags;
    // unknown44: GUESS(low); tail of the same flag-word region.
    std::uint32_t unknown44;
};

// TestBit: GUESS(low); by-value flag-word bit test, the form the listing shows (shift, test low bit).
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

// Slot5: GUESS(low); method name inferred from vtable owner and slot
class BGSQueuedTerrainInitialLoad
{
public:
    virtual std::uint32_t Slot5() const;
    // Function51ada0: GUESS(low); name from the task sheet, behaviour decoded from the listing.
    void Function51ada0();
    // Function51c570, ReleaseQueuedTerrain: GUESS(low); existing matched leaf, unchanged.
    void Function51c570();
    // unknown08: GUESS(low); chain head that holds the committed node.
    QueuedLoadNode* unknown08;
    // unknown10: GUESS(low); meaning unknown.
    void* unknown10;
    // unknown18, target: GUESS(low); the same field at 0x18. Function51ada0 reads it as the pending
    // node taken into the chain head, and Function51c570 keeps its earlier name for it.
    union
    {
        QueuedLoadNode* unknown18;
        void* target;
    };
};

static_assert(sizeof(QueuedLoadNode) == 0x48, "QueuedLoadNode size");
static_assert(offsetof(QueuedLoadNode, unknown38) == 0x38, "QueuedLoadNode next offset");
static_assert(offsetof(QueuedLoadNode, flags) == 0x40, "QueuedLoadNode flags offset");
static_assert(sizeof(BGSQueuedTerrainInitialLoad) == 0x20, "BGSQueuedTerrainInitialLoad size");
