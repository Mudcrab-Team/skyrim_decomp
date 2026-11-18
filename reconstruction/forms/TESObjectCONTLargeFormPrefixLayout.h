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
// TESObjectCONT: EXE_RTTI
// Represented component at 0: TESBoundAnimObject
// Represented component at 48: TESContainer
// Represented component at 72: TESFullName
// Represented component at 88: TESModelTextureSwap
// Represented component at 144: TESWeightForm
class TESObjectCONTLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public ContainerComponentLayout, public FullNameComponentLayout, public ModelTextureSwapComponentLayout, public WeightComponentLayout {
public:
    TESObjectCONTLargeFormPrefixLayout();
    ~TESObjectCONTLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(TESObjectCONTLargeFormPrefixLayout) == 160, "represented prefix only");
struct TESObjectCONTLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    ContainerComponentLayout component1;
    FullNameComponentLayout component2;
    ModelTextureSwapComponentLayout component3;
    WeightComponentLayout component4;
};
static_assert(offsetof(TESObjectCONTLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(TESObjectCONTLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(TESObjectCONTLargeFormPrefixLayoutStorageLayout, component2) == 72, "target component offset");
static_assert(offsetof(TESObjectCONTLargeFormPrefixLayoutStorageLayout, component3) == 88, "target component offset");
static_assert(offsetof(TESObjectCONTLargeFormPrefixLayoutStorageLayout, component4) == 144, "target component offset");
}
