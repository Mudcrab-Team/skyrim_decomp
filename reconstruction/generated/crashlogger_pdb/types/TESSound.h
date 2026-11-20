// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESSound; size 0x38
#pragma once

#include "TESBoundAnimObject.h"
struct BGSSoundDescriptorForm;
struct TESSound {
    TESBoundAnimObject _base;
    BGSSoundDescriptorForm* descriptor;
};
static_assert(sizeof(TESSound) == 56, "TESSound layout differs from the PDB");
