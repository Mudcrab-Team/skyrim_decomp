// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundDescriptorForm; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "BSISoundDescriptor_cac04df2.h"
#include "TESForm_4074aa87.h"
struct BGSSoundDescriptor;
struct BGSSoundDescriptorForm_de361764 {
    TESForm_4074aa87 _base;
    BSISoundDescriptor_cac04df2 _base_BSISoundDescriptor;
    BGSSoundDescriptor* soundDescriptor;
};
static_assert(sizeof(BGSSoundDescriptorForm_de361764) == 48, "BGSSoundDescriptorForm_de361764 layout differs from the PDB");
