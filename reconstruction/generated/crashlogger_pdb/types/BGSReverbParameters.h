// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSReverbParameters; size 0x38
#pragma once

#include "BSIReverbType.h"
#include "ReverbParams.h"
#include "TESForm.h"
struct BGSReverbParameters {
    TESForm _base;
    BSIReverbType _base_BSIReverbType;
    ReverbParams data;
    unsigned short pad36;
};
static_assert(sizeof(BGSReverbParameters) == 56, "BGSReverbParameters layout differs from the PDB");
