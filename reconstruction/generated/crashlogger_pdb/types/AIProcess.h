// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AIProcess; size 0x140
#pragma once

#include "ActorPackage.h"
#include "BSSimpleList_RE__ObjectstoAcquire_fd80da0e.h"
#include "BSSimpleList_RE__TESObjectREFR_8fb2ed7e_fa203e2b.h"
#include "BSTArray_RE__AIProcess__EquippedObject_d9817b79.h"
#include "BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc.h"
struct CachedValues;
struct HighProcessData_52396750;
struct MiddleHighProcessData_13c8f195;
struct MiddleLowProcessData_862b40e7;
struct ObjectstoAcquire;
struct TESForm;
struct AIProcess {
    MiddleLowProcessData_862b40e7* middleLow;
    MiddleHighProcessData_13c8f195* middleHigh;
    HighProcessData_52396750* high;
    ActorPackage currentPackage;
    float hourLastProcessed;
    float dateLastProcessed;
    CachedValues* cachedValues;
    int numberItemsActivate;
    unsigned int pad05C;
    BSSimpleList_RE__ObjectstoAcquire_fd80da0e objects;
    BSSimpleList_RE__TESObjectREFR_8fb2ed7e_fa203e2b genericLocations;
    ObjectstoAcquire* acquireObject;
    ObjectstoAcquire* savedAcquireObject;
    float essentialDownTimer;
    float deathTime;
    float trackedDamage;
    unsigned int pad09C;
    BSTArray_RE__AIProcess__EquippedObject_d9817b79 equippedForms;
    BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc unk0B8;
    TESForm* equippedObjects[2];
    unsigned long long unk100;
    unsigned long long unk108;
    unsigned int followTarget;
    unsigned int target;
    unsigned int arrestTarget;
    unsigned char undefined_11c[4];
    unsigned long long unk120;
    unsigned long long unk128;
    unsigned int unk130;
    unsigned short unk134;
    unsigned char lowProcessFlags;  // LowProcessFlags in the PDB is wider than this slot
    unsigned char processLevel;  // PROCESS_TYPE in the PDB is wider than this slot
    bool skippedTimeStampForPathing;
    bool ignoringCombat;
    bool endAlarmOnActor;
    bool escortingPlayer;
    unsigned int pad13C;
};
static_assert(sizeof(AIProcess) == 320, "AIProcess layout differs from the PDB");
