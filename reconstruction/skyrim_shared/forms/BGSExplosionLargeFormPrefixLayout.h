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
namespace ResearchLayouts {
// BGSExplosion: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModel
// Represented component at 104: TESEnchantableForm
// Represented component at 128: BGSPreloadable
class BGSExplosionLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelComponentLayout, public EnchantableComponentLayout, public PreloadableComponentLayout {
public:
    BGSExplosionLargeFormPrefixLayout();
    ~BGSExplosionLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    void Unk_04() override;
};
static_assert(sizeof(BGSExplosionLargeFormPrefixLayout) == 136, "represented prefix only");
struct BGSExplosionLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelComponentLayout component2;
    EnchantableComponentLayout component3;
    PreloadableVptrStorageLayout component4;
};
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component3) == 104, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component4) == 128, "target component offset");
}
