// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBase; size 0x150
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSTArray_ExtraFactionChanges__Data.h"
#include "NiPointer_BGSAttackDataMap_155ee1af.h"
#include "TESAIForm__Data.h"
#include "TESAIForm__PackageList.h"
#include "TESActorBaseData__Data.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct ActorValueOwner__VFTable;
struct BGSAttackDataForm__VFTable;
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSPerkRankArray__VFTable;
struct BGSSkinForm__VFTable;
struct BGSVoiceType_932b9e72;
struct TESAIForm__VFTable;
struct TESActorBaseData__VFTable;
struct TESActorBase__VFTable;
struct TESContainer__Entry;
struct TESContainer__VFTable;
struct TESForm_4074aa87;
struct TESFullName__VFTable;
struct TESLevItem;
struct TESObjectARMO;
struct TESSpellList__Data;
struct TESSpellList__VFTable;
struct TESActorBase {
    TESActorBase__VFTable* vftable_TESActorBase_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESActorBaseData__VFTable* vftable_TESActorBaseData_30;
    TESActorBaseData__Data ActorData_38;
    TESLevItem* DeathItem_50;
    BGSVoiceType_932b9e72* VoiceType_58;
    TESForm_4074aa87* BaseTemplateForm_60;
    TESForm_4074aa87** TemplateForms_68;
    BSTArray_ExtraFactionChanges__Data Factions_70;
    TESContainer__VFTable* vftable_TESContainer_88;
    TESContainer__Entry** ContainerEntries_90;
    int ContainerEntriesCount_98;
    char _pad_9C[4];
    TESSpellList__VFTable* vftable_TESSpellList_A0;
    TESSpellList__Data* ActorEffects_A8;
    TESAIForm__VFTable* vftable_TESAIForm_B0;
    TESAIForm__Data AIData_B8;
    char _pad_C4[4];
    TESAIForm__PackageList AIPackages_C8;
    TESFullName__VFTable* vftable_TESFullName_D8;
    BSFixedString Text_E0;
    ActorValueOwner__VFTable* vftable_ActorValueOwner_E8;
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_F0;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_F8;
    BGSSkinForm__VFTable* vftable_BGSSkinForm_100;
    TESObjectARMO* Skin_108;
    BGSKeywordForm__VFTable* vftable_BGSKeywordForm_110;
    BGSKeyword_f67121b2** Keywords_118;
    int Count_120;
    char _pad_124[4];
    BGSAttackDataForm__VFTable* vftable_BGSAttackDataForm_128;
    NiPointer_BGSAttackDataMap_155ee1af AttackDataMap_130;
    BGSPerkRankArray__VFTable* vftable_BGSPerkRankArray_138;
    void* RankArray_140;
    int PerkCount_148;
    char _pad_14C[4];
};
static_assert(sizeof(TESActorBase) == 336, "TESActorBase layout differs from the PDB");
