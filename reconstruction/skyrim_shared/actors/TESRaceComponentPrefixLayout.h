// Source exposure: mixed (pinned community component declarations; independent target RTTI and secondary-slot analysis).
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/{B,T,N} component headers; MIT.
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESFullName, TESDescription, TESSpellList, BGSSkinForm, BGSBipedObjectForm, BGSKeywordForm, BGSAttackDataForm, TESModel, TESTexture, TESIcon, BGSPickupPutdownSounds, BGSPreloadable, TESImageSpaceModifiableForm, BGSDestructibleObjectForm, BSFixedString, BGSLocalizedStringDL, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace, BGSNote, BGSHazard, BGSProjectile: EXE_RTTI
// All ResearchLayouts class and struct names ending Layout, the physical storage wrappers and prefix mirror names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "../forms/FormComponentLayout.h"
namespace ResearchLayouts {
class TESRaceComponentPrefixLayout :
    public FormHeaderLayout,
    public FullNameComponentLayout,
    public DescriptionComponentLayout,
    public SpellListComponentLayout,
    public SkinComponentLayout,
    public BipedComponentLayout,
    public KeywordComponentLayout,
    public AttackDataComponentLayout {
public:
    TESRaceComponentPrefixLayout();
    ~TESRaceComponentPrefixLayout() override;
};
static_assert(sizeof(TESRaceComponentPrefixLayout) == 152, "component-base prefix only, owner data tail unclaimed");
struct TESRaceComponentPrefixLayoutStorage {
    FormHeaderLayout component0;
    FullNameComponentLayout component1;
    DescriptionComponentLayout component2;
    SpellListComponentLayout component3;
    SkinComponentLayout component4;
    BipedComponentLayout component5;
    KeywordComponentLayout component6;
    AttackDataComponentLayout component7;
};
static_assert(sizeof(TESRaceComponentPrefixLayoutStorage) == sizeof(TESRaceComponentPrefixLayout), "physical component-prefix mirror");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component0) == 0, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component1) == 32, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component2) == 48, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component3) == 64, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component4) == 80, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component5) == 96, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component6) == 112, "target direct-base offset");
static_assert(offsetof(TESRaceComponentPrefixLayoutStorage, component7) == 136, "target direct-base offset");
}
