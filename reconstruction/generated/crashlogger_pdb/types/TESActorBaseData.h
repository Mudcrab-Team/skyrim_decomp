// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBaseData; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ACTOR_BASE_DATA.h"
#include "BSTArray_RE__FACTION_RANK_2356c979.h"
#include "BaseFormComponent.h"
struct BGSVoiceType;
struct TESForm;
struct TESLevItem_61cd676b;
struct TESActorBaseData {
    BaseFormComponent _base;
    ACTOR_BASE_DATA actorData;
    TESLevItem_61cd676b* deathItem;
    BGSVoiceType* voiceType;
    TESForm* baseTemplateForm;
    unsigned int changeFlags;
    unsigned int pad3C;
    BSTArray_RE__FACTION_RANK_2356c979 factions;
};
static_assert(sizeof(TESActorBaseData) == 88, "TESActorBaseData layout differs from the PDB");
