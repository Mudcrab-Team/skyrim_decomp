// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/RaceComponentLayout.h"
namespace ResearchLayouts {
class ImpactDataPointeeLayout;
class MaterialPointeeLayout;
class AttackDamageComponentLayout : public FormComponentLayout {
public:
    ~AttackDamageComponentLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    virtual std::uint16_t GetAttackDamage() const;
    std::uint16_t attackDamage;
};
static_assert(sizeof(AttackDamageComponentLayout) == 16, "community component storage");
}
