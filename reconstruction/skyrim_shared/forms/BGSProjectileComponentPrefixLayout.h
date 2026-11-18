// Source exposure: mixed (pinned community component declarations; independent target RTTI and secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/{B,T,N} component headers; MIT.
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESFullName, TESDescription, TESSpellList, BGSSkinForm, BGSBipedObjectForm, BGSKeywordForm, BGSAttackDataForm, TESModel, TESTexture, TESIcon, BGSPickupPutdownSounds, BGSPreloadable, TESImageSpaceModifiableForm, BGSDestructibleObjectForm, BSFixedString, BGSLocalizedStringDL, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace, BGSNote, BGSHazard, BGSProjectile: EXE_RTTI
// All ResearchLayouts class and struct names ending Layout, the physical storage wrappers and prefix mirror names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "FormComponentLayout.h"
namespace ResearchLayouts {
class BGSProjectileComponentPrefixLayout :
    public BoundObjectFormHeaderLayout,
    public FullNameComponentLayout,
    public ModelComponentLayout,
    public PreloadableComponentLayout,
    public DestructibleComponentLayout {
public:
    BGSProjectileComponentPrefixLayout();
    ~BGSProjectileComponentPrefixLayout() override;
};
static_assert(sizeof(BGSProjectileComponentPrefixLayout) == 128, "component-base prefix only, owner data tail unclaimed");
struct BGSProjectileComponentPrefixLayoutStorage {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelComponentLayout component2;
    PreloadableVptrStorageLayout component3;
    DestructibleComponentLayout component4;
};
static_assert(sizeof(BGSProjectileComponentPrefixLayoutStorage) == sizeof(BGSProjectileComponentPrefixLayout), "physical component-prefix mirror");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component0) == 0, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component1) == 48, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component2) == 64, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component3) == 104, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component4) == 112, "target direct-base offset");
}
