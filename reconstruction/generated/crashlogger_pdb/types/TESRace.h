// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRace; size 0x4b8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSAttackDataForm.h"
#include "BGSBipedObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSSkinForm.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BGSEquipSlot_f5ce6c70.h"
#include "BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "EquipmentFlag.h"
#include "RACE_DATA.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESSpellList_4c184649.h"
#include "UnkData.h"
struct AttackAnimationArrayMap;
struct BGSArtObject_14762d66;
struct BGSBodyPartData_cf1a6e26;
struct BGSEquipSlot_15bd99b3;
struct BGSImpactDataSet_e1a4fffc;
struct BGSMaterialType;
struct BGSMovementType_1a883e57;
struct BGSSoundDescriptorForm;
struct BGSVoiceType;
struct FaceRelatedData;
struct TESObjectARMO_295db33a;
struct TESRace {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESDescription _base_TESDescription;
    TESSpellList_4c184649 _base_TESSpellList;
    BGSSkinForm _base_BGSSkinForm;
    BGSBipedObjectForm _base_BGSBipedObjectForm;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    BGSAttackDataForm _base_BGSAttackDataForm;
    unsigned char skeletonModels_raw[80];
    RACE_DATA data;
    float clampFaceGeoValue;
    float clampFaceGeoValue2;
    unsigned int pad194;
    unsigned char bodyTextureModels_raw[80];
    unsigned char behaviorGraphs_raw[80];
    unsigned char rootBehaviorGraphNames_raw[16];
    unsigned char behaviorGraphProjectNames_raw[16];
    BGSVoiceType* defaultVoiceTypes[2];
    BGSBodyPartData_cf1a6e26* bodyPartData;
    TESObjectARMO_295db33a* decapitateArmors[2];
    UnkData unk280;
    unsigned char undefined_290[8];
    UnkData unk298;
    unsigned char undefined_2a8[8];
    unsigned long long unk2B0;
    unsigned long long unk2B8;
    unsigned long long unk2C0;
    unsigned long long unk2C8;
    AttackAnimationArrayMap* attackAnimationArrayMap[2];
    BSFixedString_char_83b572b4 formEditorID;
    BGSMaterialType* bloodImpactMaterial;
    BGSImpactDataSet_e1a4fffc* impactDataSet;
    BGSArtObject_14762d66* dismemberBlood;
    BGSSoundDescriptorForm* corpseOpenSound;
    BGSSoundDescriptorForm* corpseCloseSound;
    unsigned char bipedObjectNameA_raw[256];
    BSTArray_RE__BGSEquipSlot_f5ce6c70 equipSlots;
    EquipmentFlag validEquipTypes;
    unsigned int unk42C;
    BGSEquipSlot_15bd99b3* unarmedEquipSlot;
    TESRace* morphRace;
    TESRace* armorParentRace;
    UnkData unk448;
    unsigned char undefined_458[8];
    BSTArray_RE__detail__BSFixedString_char_dee190e5 phonemeTargets;
    BGSMovementType_1a883e57* baseMoveTypes[6];
    FaceRelatedData* faceRelatedData[2];
};
static_assert(sizeof(TESRace) == 1208, "TESRace layout differs from the PDB");
