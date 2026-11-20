// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Hazard; size 0xe0
#pragma once

#include "BSExtraDataList.h"
#include "BSSoundHandle.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_NiLight_75661eb8.h"
struct BGSHazard_93ffc8c7;
struct BSHandleRefObject__VFTable;
struct BSTEventSink_BSAnimationGraphEvent___VFTable;
struct Hazard__VFTable;
struct IAnimationGraphManagerHolder__VFTable;
struct TESForm_4074aa87;
struct TESObjectCELL;
struct Hazard {
    Hazard__VFTable* vftable_Hazard_0;
    unsigned char undefined_8[8];
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    BSHandleRefObject__VFTable* vftable_BSHandleRefObject_20;
    char _pad_28[8];
    BSTEventSink_BSAnimationGraphEvent___VFTable* vftable_BSTEventSink_30;
    IAnimationGraphManagerHolder__VFTable* vftable_IAnimationGraphManagerHolder_38;
    TESForm_4074aa87* BaseForm_40;
    unsigned char undefined_48[12];
    NiPoint3_a7124070 Position_54;
    TESObjectCELL* ParentCell_60;
    char _pad_68[8];
    BSExtraDataList ExtraDataList_70;
    char _pad_88[8];
    unsigned short RefScale_90;
    char ModelState_92;
    bool PreDestroyed_93;
    unsigned char undefined_94[4];
    void* HazardDBHandle_98;
    unsigned int OwnerActorRefHandle_A0;
    float age;
    float lifetime;
    float TargetTimer_AC;
    float Radius_B0;
    float magnitude;
    BGSHazard_93ffc8c7* hazard;
    NiPointer_NiLight_75661eb8 Light_C0;
    BSSoundHandle sound;
    int flags;
    unsigned char undefined_d8[8];
};
static_assert(sizeof(Hazard) == 224, "Hazard layout differs from the PDB");
