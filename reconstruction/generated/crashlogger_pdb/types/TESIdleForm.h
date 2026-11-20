// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESIdleForm; size 0x68
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSString.h"
#include "TESCondition.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESIdleForm__Data.h"
struct NiFormArray;
struct TESIdleForm__VFTable;
struct TESIdleForm {
    TESIdleForm__VFTable* vftable_TESIdleForm_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESCondition Conditions_20;
    TESIdleForm__Data IdleData_28;
    char _pad_2E[2];
    NiFormArray* ChildIdles_30;
    TESIdleForm* ParentIdle_38;
    TESIdleForm* PreviousIdle_40;
    BSFixedString AnimationFileName_48;
    BSFixedString AnimationEventName_50;
    BSString FormEditorId_58;
};
static_assert(sizeof(TESIdleForm) == 104, "TESIdleForm layout differs from the PDB");
