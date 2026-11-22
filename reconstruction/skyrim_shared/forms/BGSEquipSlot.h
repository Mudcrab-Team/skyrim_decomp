// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold at the pinned checkouts.
// BGSEquipSlot, BGSEquipSlot::InitializeData, BGSEquipSlot::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEquipSlot::parentSlots, BGSEquipSlot::ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "TESForm.h"

class BGSEquipSlot;

// EquipSlotArray: STANDIN GUESS(low); the parent-slot array and its allocator.
struct EquipSlotArray {
    void Release();
    void Clear()
    {
        if (data) {
            Release();
            size = 0;
        }
    }

    BGSEquipSlot** data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};

// BGSDefaultObjectManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSDefaultObjectManager {
public:
    // DefaultObjectID::kLeftHandEquip, DefaultObjectID::kRightHandEquip: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    enum : std::uint32_t {
        kLeftHandEquip = 19,
        kRightHandEquip = 20,
    };

    // GetDefaultObject: GUESS(low); shared binding for the indexed lookup.
    static TESForm* GetDefaultObject(std::uint32_t a_index);
};

// g_memoryContext_tls_0x768: GUESS(low)
extern __declspec(thread) std::uint32_t g_memoryContext_tls_0x768;

class BGSEquipSlot : public TESForm {
public:
    void InitializeData() override;  // 04
    void ClearData() override;       // 05

    // IsHandEquipSlot, ContainsSlot: GUESS(low)
    static bool IsHandEquipSlot(const BGSEquipSlot* a_slot);
    bool ContainsSlot(const TESForm* a_slot) const;

    EquipSlotArray parentSlots;     // 20
    std::uint32_t  flags;           // 38
    std::uint32_t  pad3C;           // 3C
};
