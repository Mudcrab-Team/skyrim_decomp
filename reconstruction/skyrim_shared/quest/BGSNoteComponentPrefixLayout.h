// Source exposure: mixed (pinned community component declarations; independent target RTTI and secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/{B,T,N} component headers; MIT.
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESFullName, TESDescription, TESSpellList, BGSSkinForm, BGSBipedObjectForm, BGSKeywordForm, BGSAttackDataForm, TESModel, TESTexture, TESIcon, BGSPickupPutdownSounds, BGSPreloadable, TESImageSpaceModifiableForm, BGSDestructibleObjectForm, BSFixedString, BGSLocalizedStringDL, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace, BGSNote, BGSHazard, BGSProjectile: EXE_RTTI
// All ResearchLayouts class and struct names ending Layout, the physical storage wrappers and prefix mirror names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/forms/FormComponentLayout.h"
namespace ResearchLayouts {
class BGSNoteComponentPrefixLayout :
    public BoundObjectFormHeaderLayout,
    public ModelComponentLayout,
    public FullNameComponentLayout,
    public IconComponentLayout,
    public PickupSoundsComponentLayout {
public:
    BGSNoteComponentPrefixLayout();
    ~BGSNoteComponentPrefixLayout() override;
};
static_assert(sizeof(BGSNoteComponentPrefixLayout) == 144, "component-base prefix only, owner data tail unclaimed");
struct BGSNoteComponentPrefixLayoutStorage {
    BoundObjectFormHeaderLayout component0;
    ModelComponentLayout component1;
    FullNameComponentLayout component2;
    IconComponentLayout component3;
    PickupSoundsComponentLayout component4;
};
static_assert(sizeof(BGSNoteComponentPrefixLayoutStorage) == sizeof(BGSNoteComponentPrefixLayout), "physical component-prefix mirror");
static_assert(offsetof(BGSNoteComponentPrefixLayoutStorage, component0) == 0, "target direct-base offset");
static_assert(offsetof(BGSNoteComponentPrefixLayoutStorage, component1) == 48, "target direct-base offset");
static_assert(offsetof(BGSNoteComponentPrefixLayoutStorage, component2) == 88, "target direct-base offset");
static_assert(offsetof(BGSNoteComponentPrefixLayoutStorage, component3) == 104, "target direct-base offset");
static_assert(offsetof(BGSNoteComponentPrefixLayoutStorage, component4) == 120, "target direct-base offset");
}
