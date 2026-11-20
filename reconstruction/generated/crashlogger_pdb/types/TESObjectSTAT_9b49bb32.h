// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectSTAT; size 0x80
// one of 2 different PDB types sharing this name
#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"
#include "TESObjectSTATData.h"
struct TESObjectSTAT_9b49bb32 {
    TESBoundObject _base;
    TESModelTextureSwap _base_TESModelTextureSwap;
    TESObjectSTATData data;
};
static_assert(sizeof(TESObjectSTAT_9b49bb32) == 128, "TESObjectSTAT_9b49bb32 layout differs from the PDB");
