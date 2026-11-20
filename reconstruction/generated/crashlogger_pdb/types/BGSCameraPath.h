// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSCameraPath; size 0x58
#pragma once

#include "BSSimpleList_RE__BGSCameraShot_55816dde.h"
#include "PATH_DATA.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
struct NiFormArray_60ab7697;
struct BGSCameraPath {
    TESForm _base;
    TESCondition_4d3cdc88 conditions;
    BSSimpleList_RE__BGSCameraShot_55816dde shots;
    PATH_DATA data;
    unsigned char pad39;
    unsigned short pad3A;
    unsigned int pad3C;
    NiFormArray_60ab7697* childPaths;
    BGSCameraPath* parentPath;
    BGSCameraPath* prevPath;
};
static_assert(sizeof(BGSCameraPath) == 88, "BGSCameraPath layout differs from the PDB");
