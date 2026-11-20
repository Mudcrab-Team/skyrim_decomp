// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPickupPutdownSounds; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct BGSSoundDescriptorForm;
struct BGSPickupPutdownSounds_f2d7cfc7 {
    BaseFormComponent _base;
    BGSSoundDescriptorForm* pickupSound;
    BGSSoundDescriptorForm* putdownSound;
};
static_assert(sizeof(BGSPickupPutdownSounds_f2d7cfc7) == 24, "BGSPickupPutdownSounds_f2d7cfc7 layout differs from the PDB");
