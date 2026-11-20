// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPickupPutdownSounds; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent_9d659514.h"
struct BGSSoundDescriptorForm_de361764;
struct BGSPickupPutdownSounds {
    BaseFormComponent_9d659514 _base;
    BGSSoundDescriptorForm_de361764* pickupSound;
    BGSSoundDescriptorForm_de361764* putdownSound;
};
static_assert(sizeof(BGSPickupPutdownSounds) == 24, "BGSPickupPutdownSounds layout differs from the PDB");
