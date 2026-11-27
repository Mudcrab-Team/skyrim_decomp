// BGSEquipSlot type declarations, build sse-steam-1-7-104.
//
// Exposure detail: (binary-analysis of the pinned image, community-headers).
// Source exposure: mixed
// Names and member offsets follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT). TESForm comes from
// the shared header; only the members and slots the compared code needs are declared here.
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its
// BGSEquipSlot, BGSEquipSlot::InitializeData, BGSEquipSlot::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEquipSlot::parentSlots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares BSTArray<BGSEquipSlot*>, represented by EquipArray at offset 0x20
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once

#include <cstdint>

#include "TESForm.h"

// EquipArray: GUESS STANDIN; represented BSTArray heap allocator and count.
// EquipArray, EquipArrayClear, EquipArrayReset, EquipArrayRelease, data, capacity,
// pad0C, count, pad14: GUESS(low); ownership cleanup inferred from prior near-miss.
void EquipArrayClear(void*);
void EquipArrayReset(std::uint32_t*);
void EquipArrayRelease(void*);
// EquipArrayAllocator, EquipArraySize: GUESS(low); represented allocator and size bases.
struct EquipArrayAllocator {
    ~EquipArrayAllocator() { EquipArrayRelease(this); }
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};
struct EquipArraySize {
    ~EquipArraySize() { EquipArrayReset(&count); }
    std::uint32_t count;
};
struct EquipArray : public EquipArrayAllocator, public EquipArraySize {
    ~EquipArray() {
        if (data) { EquipArrayClear(this); count = 0; }
    }
};
static_assert(sizeof(EquipArray) == 0x18, "array layout");

class BGSEquipSlot : public TESForm {
public:
    // BGSEquipSlot::BGSEquipSlot: GUESS(low); retained for deleting-destructor emission.
    BGSEquipSlot();
    // BGSEquipSlot::~BGSEquipSlot, ClearData, parentSlots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~BGSEquipSlot() override;
    void ClearData() override;
    void InitializeData() override;
    EquipArray parentSlots;
    std::uint32_t flags;
    std::uint32_t pad3C;
};
static_assert(sizeof(BGSEquipSlot) == 0x40, "equip slot size");
