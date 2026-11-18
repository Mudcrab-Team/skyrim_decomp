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
// TESAmmo: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModelTextureSwap
// Represented component at 120: TESIcon
// Represented component at 136: BGSMessageIcon
// Represented component at 160: TESValueForm
// Represented component at 176: TESWeightForm
// Represented component at 192: BGSDestructibleObjectForm
// Represented component at 208: BGSPickupPutdownSounds
// Represented component at 232: TESDescription
// Represented component at 248: BGSKeywordForm
class TESAmmoLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout, public MessageIconComponentLayout, public ValueComponentLayout, public WeightComponentLayout, public DestructibleComponentLayout, public PickupSoundsComponentLayout, public DescriptionComponentLayout, public KeywordComponentLayout {
public:
    TESAmmoLargeFormPrefixLayout();
    ~TESAmmoLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESAmmoLargeFormPrefixLayout) == 272, "represented prefix only");
struct TESAmmoLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
    MessageIconComponentLayout component4;
    ValueComponentLayout component5;
    WeightComponentLayout component6;
    DestructibleComponentLayout component7;
    PickupSoundsComponentLayout component8;
    DescriptionComponentLayout component9;
    KeywordComponentLayout component10;
};
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component3) == 120, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component4) == 136, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component5) == 160, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component6) == 176, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component7) == 192, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component8) == 208, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component9) == 232, "target component offset");
static_assert(offsetof(TESAmmoLargeFormPrefixLayoutStorageLayout, component10) == 248, "target component offset");
}
