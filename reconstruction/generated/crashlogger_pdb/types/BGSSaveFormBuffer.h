// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveFormBuffer; size 0x30
#pragma once

#include "BGSSaveGameBuffer.h"
struct TESForm;
struct BGSSaveFormBuffer {
    BGSSaveGameBuffer _base;
    unsigned long long unk18;
    unsigned long long unk20;
    TESForm* form;
};
static_assert(sizeof(BGSSaveFormBuffer) == 48, "BGSSaveFormBuffer layout differs from the PDB");
