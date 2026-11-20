// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBaseData; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_ExtraFactionChanges__Data.h"
#include "TESActorBaseData__Data.h"
struct BGSVoiceType_932b9e72;
struct TESActorBaseData__VFTable;
struct TESForm_4074aa87;
struct TESLevItem;
struct TESActorBaseData_698bb182 {
    TESActorBaseData__VFTable* vftable_TESActorBaseData_0;
    TESActorBaseData__Data ActorData_8;
    TESLevItem* DeathItem_20;
    BGSVoiceType_932b9e72* VoiceType_28;
    TESForm_4074aa87* BaseTemplateForm_30;
    TESForm_4074aa87** TemplateForms_38;
    BSTArray_ExtraFactionChanges__Data Factions_40;
};
static_assert(sizeof(TESActorBaseData_698bb182) == 88, "TESActorBaseData_698bb182 layout differs from the PDB");
