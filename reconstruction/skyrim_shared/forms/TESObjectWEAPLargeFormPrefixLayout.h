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
#include "skyrim/ai/combat/AttackDamageComponentLayout.h"
#include "skyrim/ai/combat/BlockBashComponentLayout.h"
namespace ResearchLayouts {
// TESObjectWEAP: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModelTextureSwap
// Represented component at 120: TESIcon
// Represented component at 136: TESEnchantableForm
// Represented component at 160: TESValueForm
// Represented component at 176: TESWeightForm
// Represented component at 192: TESAttackDamageForm
// Represented component at 208: BGSDestructibleObjectForm
// Represented component at 224: BGSEquipType
// Represented component at 240: BGSPreloadable
// Represented component at 248: BGSMessageIcon
// Represented component at 272: BGSPickupPutdownSounds
// Represented component at 296: BGSBlockBashData
// Represented component at 320: BGSKeywordForm
// Represented component at 344: TESDescription
class TESObjectWEAPLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public IconComponentLayout, public EnchantableComponentLayout, public ValueComponentLayout, public WeightComponentLayout, public AttackDamageComponentLayout, public DestructibleComponentLayout, public EquipTypeComponentLayout, public PreloadableComponentLayout, public MessageIconComponentLayout, public PickupSoundsComponentLayout, public BlockBashComponentLayout, public KeywordComponentLayout, public DescriptionComponentLayout {
public:
    TESObjectWEAPLargeFormPrefixLayout();
    ~TESObjectWEAPLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    void Unk_04() override;
};
static_assert(sizeof(TESObjectWEAPLargeFormPrefixLayout) == 360, "represented prefix only");
struct TESObjectWEAPLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelTextureSwapComponentLayout component2;
    IconComponentLayout component3;
    EnchantableComponentLayout component4;
    ValueComponentLayout component5;
    WeightComponentLayout component6;
    AttackDamageComponentLayout component7;
    DestructibleComponentLayout component8;
    EquipTypeComponentLayout component9;
    PreloadableVptrStorageLayout component10;
    MessageIconComponentLayout component11;
    PickupSoundsComponentLayout component12;
    BlockBashComponentLayout component13;
    KeywordComponentLayout component14;
    DescriptionComponentLayout component15;
};
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component3) == 120, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component4) == 136, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component5) == 160, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component6) == 176, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component7) == 192, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component8) == 208, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component9) == 224, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component10) == 240, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component11) == 248, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component12) == 272, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component13) == 296, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component14) == 320, "target component offset");
static_assert(offsetof(TESObjectWEAPLargeFormPrefixLayoutStorageLayout, component15) == 344, "target component offset");
}
