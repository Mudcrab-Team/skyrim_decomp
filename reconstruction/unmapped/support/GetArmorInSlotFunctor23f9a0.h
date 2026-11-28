// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// GetArmorInSlotFunctor23f9a0: CRASHLOGGER_PDB(59818@2026.10.24)
// BipedModel23f9a0, BaseForm23f9a0, ArmorForm23f9a0, EntryData23f9a0, HasSlot, Visit, formType, bipedModel, object, slotIndex, foundArmor: GUESS(low)
#pragma once

#include <cstdint>

class BipedModel23f9a0
{
public:
    bool HasSlot(std::uint32_t slot) const;
};

struct BaseForm23f9a0
{
    std::uint8_t unk00[0x1A];  // 00
    std::uint8_t formType;     // 1A
};

struct ArmorForm23f9a0 : BaseForm23f9a0
{
    std::uint8_t unk1B[0x195];    // 01B
    BipedModel23f9a0 bipedModel;  // 1B0
};

struct EntryData23f9a0
{
    BaseForm23f9a0* object;  // 00
};

class GetArmorInSlotFunctor23f9a0
{
public:
    virtual ~GetArmorInSlotFunctor23f9a0();
    virtual std::uint32_t Visit(EntryData23f9a0* entry);

    std::uint32_t slotIndex;     // 08
    BaseForm23f9a0* foundArmor;  // 10
};
