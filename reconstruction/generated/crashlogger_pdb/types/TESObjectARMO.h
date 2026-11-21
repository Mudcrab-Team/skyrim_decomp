// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectARMO; size 0x228
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSBipedObjectForm__BipedData.h"
#include "BGSLocalizedStringDL_8410e68a.h"
#include "BGSMessageIcon.h"
#include "BSFixedString.h"
#include "BSTArray_TESObjectARMA_d4e84c19.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESIcon.h"
#include "TESModelRDT.h"
#include "TESModelTextureSwap.h"
struct BGSBipedObjectForm__VFTable;
struct BGSBlockBashData__VFTable;
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSImpactDataSet;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSMaterialType_c56427e2;
struct BGSPickupPutdownSounds__VFTable;
struct BGSSoundDescriptorForm_de361764;
struct EnchantmentItem;
struct TESBipedModelForm__VFTable;
struct TESDescription__VFTable;
struct TESEnchantableForm__VFTable;
struct TESFullName__VFTable;
struct TESObjectARMO__VFTable;
struct TESRaceForm__VFTable;
struct TESRace_e57679c0;
struct TESValueForm__VFTable;
struct TESWeightForm__VFTable;
struct TESObjectARMO {
    TESObjectARMO__VFTable* vftable_TESObjectARMO_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESFullName__VFTable* vftable_TESFullName_30;
    BSFixedString Text_38;
    TESRaceForm__VFTable* vftable_TESRaceForm_40;
    TESRace_e57679c0* Race_48;
    TESEnchantableForm__VFTable* vftable_TESEnchantableForm_50;
    EnchantmentItem* FormEnchanting_58;
    unsigned short CastingType_60;
    unsigned short AmountOfEnchantment_62;
    char _pad_64[4];
    TESValueForm__VFTable* vftable_TESValueForm_68;
    unsigned int ValueAmount_70;
    char _pad_74[4];
    TESWeightForm__VFTable* vftable_TESWeightForm_78;
    float WeightValue_80;
    char _pad_84[4];
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_88;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_90;
    BGSPickupPutdownSounds__VFTable* vftable_BGSPickupPutdownSounds_98;
    BGSSoundDescriptorForm_de361764* PickupSound_A0;
    BGSSoundDescriptorForm_de361764* PutdownSound_A8;
    TESBipedModelForm__VFTable* vftable_TESBipedModelForm_B0;
    TESModelTextureSwap WorldModels_B8[2];
    TESIcon InventoryIcons_128[2];
    BGSMessageIcon MessageIcons_148[2];
    TESModelRDT ConstraintTemplate_178;
    BGSEquipType__VFTable* vftable_BGSEquipType_1A0;
    BGSEquipSlot* EquipSlot_1A8;
    BGSBipedObjectForm__VFTable* vftable_BGSBipedObjectForm_1B0;
    BGSBipedObjectForm__BipedData ModelData_1B8;
    BGSBlockBashData__VFTable* vftable_BGSBlockBashData_1C0;
    BGSImpactDataSet* BlockBashImpactDataSet_1C8;
    BGSMaterialType_c56427e2* AltBlockMaterialType_1D0;
    BGSKeywordForm__VFTable* vftable_BGSKeywordForm_1D8;
    BGSKeyword_f67121b2** Keywords_1E0;
    int Count_1E8;
    char _pad_1EC[4];
    TESDescription__VFTable* vftable_TESDescription_1F0;
    unsigned int FileOffset_1F8;
    BGSLocalizedStringDL_8410e68a DescriptionText_1FC;
    int ArmorRatingInternalValue_200;
    char _pad_204[4];
    BSTArray_TESObjectARMA_d4e84c19 ArmorAddons_208;
    TESObjectARMO* TemplateArmor_220;
};
static_assert(sizeof(TESObjectARMO) == 552, "TESObjectARMO layout differs from the PDB");
