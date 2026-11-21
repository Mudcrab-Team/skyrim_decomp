// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRace; size 0x4b8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSAttackDataForm_d5edfa82.h"
#include "BGSBipedObjectForm_e2170940.h"
#include "BGSKeywordForm.h"
#include "BGSSkinForm_e15ffb13.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_BGSInstancedQuestObjective.h"
#include "BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19.h"
#include "BSTArray_RE__detail__BSFixedString_char_dee190e5_40d0985f.h"
#include "EnumSet_RE__TESRace__EquipmentFlag_unsigned_int_0edabe47.h"
#include "RACE_DATA_45756db8.h"
#include "TESDescription_99869432.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
#include "TESSpellList.h"
struct AttackAnimationArrayMap_f7086a69;
struct BGSArtObject;
struct BGSBodyPartData;
struct BGSEquipSlot;
struct BGSImpactDataSet;
struct BGSMaterialType_c56427e2;
struct BGSMovementType;
struct BGSSoundDescriptorForm_de361764;
struct BGSVoiceType_932b9e72;
struct FaceRelatedData;
struct TESObjectARMO;
struct TESRace_e57679c0 {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESDescription_99869432 _base_TESDescription;
    TESSpellList _base_TESSpellList;
    BGSSkinForm_e15ffb13 _base_BGSSkinForm;
    BGSBipedObjectForm_e2170940 _base_BGSBipedObjectForm;
    BGSKeywordForm _base_BGSKeywordForm;
    BGSAttackDataForm_d5edfa82 _base_BGSAttackDataForm;
    unsigned char skeletonModels_raw[80];
    RACE_DATA_45756db8 data;
    float clampFaceGeoValue;
    float clampFaceGeoValue2;
    unsigned int pad194;
    unsigned char bodyTextureModels_raw[80];
    unsigned char behaviorGraphs_raw[80];
    unsigned char rootBehaviorGraphNames_raw[16];
    unsigned char behaviorGraphProjectNames_raw[16];
    BGSVoiceType_932b9e72* defaultVoiceTypes[2];
    BGSBodyPartData* bodyPartData;
    TESObjectARMO* decapitateArmors[2];
    BSTArray_BGSInstancedQuestObjective fld280raw;
    BSTArray_BGSInstancedQuestObjective fld298raw;
    unsigned long long unk2B0;
    unsigned long long unk2B8;
    unsigned long long unk2C0;
    unsigned long long unk2C8;
    AttackAnimationArrayMap_f7086a69* attackAnimationArrayMap[2];
    BSFixedString_char_83b572b4 formEditorID;
    BGSMaterialType_c56427e2* bloodImpactMaterial;
    BGSImpactDataSet* impactDataSet;
    BGSArtObject* dismemberBlood;
    BGSSoundDescriptorForm_de361764* corpseOpenSound;
    BGSSoundDescriptorForm_de361764* corpseCloseSound;
    unsigned char bipedObjectNameA_raw[256];
    BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19 equipSlots;
    EnumSet_RE__TESRace__EquipmentFlag_unsigned_int_0edabe47 validEquipTypes;
    unsigned int unk42C;
    BGSEquipSlot* unarmedEquipSlot;
    TESRace_e57679c0* morphRace;
    TESRace_e57679c0* armorParentRace;
    BSTArray_BGSInstancedQuestObjective fld448raw;
    BSTArray_RE__detail__BSFixedString_char_dee190e5_40d0985f phonemeTargets;
    BGSMovementType* baseMoveTypes[6];
    FaceRelatedData* faceRelatedData[2];
};
static_assert(sizeof(TESRace_e57679c0) == 1208, "TESRace_e57679c0 layout differs from the PDB");
