// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// BGSEquipSlot, BGSEquipSlot::sub_140331580: CRASHLOGGER_PDB(59818@2026.10.24)
// parentSlots: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EquipSlotArray, unk00, unk0C, unk14: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BGSEquipSlot;

struct EquipSlotArray
{
    BGSEquipSlot* operator[](std::uint32_t a_index) const { return data[a_index]; }

    BGSEquipSlot** data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};
static_assert(sizeof(EquipSlotArray) == 0x18, "EquipSlotArray size");

class BGSEquipSlot
{
public:
    bool sub_140331580(const BGSEquipSlot* a_other) const;

    std::uint8_t unk00[0x20];
    EquipSlotArray parentSlots;
};
static_assert(offsetof(BGSEquipSlot, parentSlots) == 0x20, "BGSEquipSlot::parentSlots offset");
