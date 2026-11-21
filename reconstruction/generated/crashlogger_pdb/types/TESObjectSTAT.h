// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectSTAT; size 0x80
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESBoundObject_fc790793.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESObjectSTATData_59ea86db.h"
struct TESObjectSTAT {
    TESBoundObject_fc790793 _base;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESObjectSTATData_59ea86db data;
};
static_assert(sizeof(TESObjectSTAT) == 128, "TESObjectSTAT layout differs from the PDB");
