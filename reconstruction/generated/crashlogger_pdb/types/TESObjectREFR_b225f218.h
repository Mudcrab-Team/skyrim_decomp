// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectREFR; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSHandleRefObject.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
#include "ExtraDataList.h"
#include "IAnimationGraphManagerHolder_f623b5a9.h"
#include "OBJ_REFR.h"
#include "TESForm.h"
struct LOADED_REF_DATA;
struct TESObjectCELL_f81013b3;
struct TESObjectREFR_b225f218 {
    TESForm _base;
    BSHandleRefObject _base_BSHandleRefObject;
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base_BSTEventSink_RE_BSAnimationGraphEvent_;
    IAnimationGraphManagerHolder_f623b5a9 _base_IAnimationGraphManagerHolder;
    OBJ_REFR data;
    TESObjectCELL_f81013b3* parentCell;
    LOADED_REF_DATA* loadedData;
    ExtraDataList extraList;
    unsigned long long unk88;
    unsigned short refScale;
    unsigned char modelState;
    bool preDestroyed;
    unsigned int pad94;
};
static_assert(sizeof(TESObjectREFR_b225f218) == 160, "TESObjectREFR_b225f218 layout differs from the PDB");
