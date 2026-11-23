// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include "../actors/RaceComponentLayout.h"
#include "../../skyrim/interface/MessageIconComponentLayout.h"
namespace ResearchLayouts {
// TESObjectMISC: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModelTextureSwap
// Represented component at 120: TESIcon
// Represented component at 136: TESValueForm
// Represented component at 152: TESWeightForm
// Represented component at 168: BGSDestructibleObjectForm
// Represented component at 184: BGSMessageIcon
// Represented component at 208: BGSPickupPutdownSounds
// Represented component at 232: BGSKeywordForm
class TESObjectMISCLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout, public ValueComponentLayout, public WeightComponentLayout, public DestructibleComponentLayout, public MessageIconComponentLayout, public PickupSoundsComponentLayout, public KeywordComponentLayout {
public:
    TESObjectMISCLargeFormPrefixLayout();
    ~TESObjectMISCLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectMISCLargeFormPrefixLayout) == 256, "represented prefix only");
struct TESObjectMISCLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
    ValueComponentLayout component4;
    WeightComponentLayout component5;
    DestructibleComponentLayout component6;
    MessageIconComponentLayout component7;
    PickupSoundsComponentLayout component8;
    KeywordComponentLayout component9;
};
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component3) == 120, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component4) == 136, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component5) == 152, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component6) == 168, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component7) == 184, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component8) == 208, "target component offset");
static_assert(offsetof(TESObjectMISCLargeFormPrefixLayoutStorageLayout, component9) == 232, "target component offset");
}
