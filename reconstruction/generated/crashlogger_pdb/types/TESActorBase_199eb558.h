// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBase; size 0x150
// one of 2 different PDB types sharing this name
#pragma once

#include "ActorValueOwner.h"
#include "BGSAttackDataForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSPerkRankArray.h"
#include "BGSSkinForm.h"
#include "TESAIForm.h"
#include "TESActorBaseData.h"
#include "TESBoundAnimObject.h"
#include "TESContainer.h"
#include "TESFullName.h"
#include "TESSpellList_4c184649.h"
struct TESActorBase_199eb558 {
    TESBoundAnimObject _base;
    TESActorBaseData _base_TESActorBaseData;
    TESContainer _base_TESContainer;
    TESSpellList_4c184649 _base_TESSpellList;
    TESAIForm _base_TESAIForm;
    TESFullName _base_TESFullName;
    ActorValueOwner _base_ActorValueOwner;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSSkinForm _base_BGSSkinForm;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    BGSAttackDataForm _base_BGSAttackDataForm;
    BGSPerkRankArray _base_BGSPerkRankArray;
};
static_assert(sizeof(TESActorBase_199eb558) == 336, "TESActorBase_199eb558 layout differs from the PDB");
