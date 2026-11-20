// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectREFR; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESFileContainer_70f0bdf4.h"
struct TESBoundObject;
struct TESObjectCELL;
struct TESObjectREFR__VFTable;
struct TESObjectREFR {
    TESObjectREFR__VFTable* vftable;
    TESFileContainer_70f0bdf4 formSourceFiles;
    unsigned int formFlags;
    unsigned int formId;
    unsigned short formGameFlags;
    unsigned char formType;
    char _pad_1B[5];
    char _bshandle_20[8];
    char _bshandle_28[8];
    char _bst_animgraph_30[8];
    char _ianimgraphmgrholder_38[8];
    TESBoundObject* fldobjectReference;
    char rotation[12];
    char position[12];
    TESObjectCELL* parentCell;
    char loadedData[8];
    unsigned char extraList[24];
    unsigned long long unk88;
    unsigned short refScale;
    char modelState;
    bool preDestroyed;
    unsigned int pad94;
    unsigned char undefined_98[8];
};
static_assert(sizeof(TESObjectREFR) == 160, "TESObjectREFR layout differs from the PDB");
