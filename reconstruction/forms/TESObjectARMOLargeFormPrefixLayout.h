// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include "RaceComponentLayout.h"
namespace ResearchLayouts {
// TESObjectARMO: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESRaceForm
// Represented component at 80: TESEnchantableForm
// Represented component at 104: TESValueForm
// Represented component at 120: TESWeightForm
// Represented component at 136: BGSDestructibleObjectForm
// Represented component at 152: BGSPickupPutdownSounds
class TESObjectARMOLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public RaceComponentLayout, public EnchantableComponentLayout, public ValueComponentLayout, public WeightComponentLayout, public DestructibleComponentLayout, public PickupSoundsComponentLayout {
public:
    TESObjectARMOLargeFormPrefixLayout();
    ~TESObjectARMOLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectARMOLargeFormPrefixLayout) == 176, "represented prefix only");
struct TESObjectARMOLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    RaceComponentLayout component2;
    EnchantableComponentLayout component3;
    ValueComponentLayout component4;
    WeightComponentLayout component5;
    DestructibleComponentLayout component6;
    PickupSoundsComponentLayout component7;
};
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component3) == 80, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component4) == 104, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component5) == 120, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component6) == 136, "target component offset");
static_assert(offsetof(TESObjectARMOLargeFormPrefixLayoutStorageLayout, component7) == 152, "target component offset");
}
