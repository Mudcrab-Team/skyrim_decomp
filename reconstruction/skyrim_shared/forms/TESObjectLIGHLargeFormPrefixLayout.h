// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include "skyrim_shared/actors/RaceComponentLayout.h"
#include "skyrim/interface/MessageIconComponentLayout.h"
namespace ResearchLayouts {
// TESObjectLIGH: EXE_RTTI
// Represented component at 0: TESBoundAnimObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModelTextureSwap
// Represented component at 120: TESIcon
// Represented component at 136: BGSMessageIcon
// Represented component at 160: TESWeightForm
// Represented component at 176: TESValueForm
// Represented component at 192: BGSDestructibleObjectForm
// Represented component at 208: BGSEquipType
class TESObjectLIGHLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout, public MessageIconComponentLayout, public WeightComponentLayout, public ValueComponentLayout, public DestructibleComponentLayout, public EquipTypeComponentLayout {
public:
    TESObjectLIGHLargeFormPrefixLayout();
    ~TESObjectLIGHLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectLIGHLargeFormPrefixLayout) == 224, "represented prefix only");
struct TESObjectLIGHLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
    MessageIconComponentLayout component4;
    WeightComponentLayout component5;
    ValueComponentLayout component6;
    DestructibleComponentLayout component7;
    EquipTypeComponentLayout component8;
};
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component3) == 120, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component4) == 136, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component5) == 160, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component6) == 176, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component7) == 192, "target component offset");
static_assert(offsetof(TESObjectLIGHLargeFormPrefixLayoutStorageLayout, component8) == 208, "target component offset");
}
