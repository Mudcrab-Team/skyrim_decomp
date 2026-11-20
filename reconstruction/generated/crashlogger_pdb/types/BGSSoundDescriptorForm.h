// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundDescriptorForm; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSISoundDescriptor.h"
#include "TESForm.h"
struct BGSSoundDescriptor_3b5294f3;
struct BGSSoundDescriptorForm {
    TESForm _base;
    BSISoundDescriptor _base_BSISoundDescriptor;
    BGSSoundDescriptor_3b5294f3* soundDescriptor;
};
static_assert(sizeof(BGSSoundDescriptorForm) == 48, "BGSSoundDescriptorForm layout differs from the PDB");
