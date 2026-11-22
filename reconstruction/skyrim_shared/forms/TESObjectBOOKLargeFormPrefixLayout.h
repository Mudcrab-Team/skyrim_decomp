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
// TESObjectBOOK: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModelTextureSwap
// Represented component at 120: TESIcon
// Represented component at 136: TESValueForm
// Represented component at 152: TESWeightForm
// Represented component at 168: TESDescription
// Represented component at 184: BGSDestructibleObjectForm
// Represented component at 200: BGSMessageIcon
// Represented component at 224: BGSPickupPutdownSounds
// Represented component at 248: BGSKeywordForm
class TESObjectBOOKLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout, public ValueComponentLayout, public WeightComponentLayout, public DescriptionComponentLayout, public DestructibleComponentLayout, public MessageIconComponentLayout, public PickupSoundsComponentLayout, public KeywordComponentLayout {
public:
    TESObjectBOOKLargeFormPrefixLayout();
    ~TESObjectBOOKLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectBOOKLargeFormPrefixLayout) == 272, "represented prefix only");
struct TESObjectBOOKLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
    ValueComponentLayout component4;
    WeightComponentLayout component5;
    DescriptionComponentLayout component6;
    DestructibleComponentLayout component7;
    MessageIconComponentLayout component8;
    PickupSoundsComponentLayout component9;
    KeywordComponentLayout component10;
};
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component3) == 120, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component4) == 136, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component5) == 152, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component6) == 168, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component7) == 184, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component8) == 200, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component9) == 224, "target component offset");
static_assert(offsetof(TESObjectBOOKLargeFormPrefixLayoutStorageLayout, component10) == 248, "target component offset");
}
