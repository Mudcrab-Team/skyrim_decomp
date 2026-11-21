// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Sound; size 0x10
#pragma once

#include "Flag_a4a94b8a.h"
struct BGSSoundDescriptorForm;
struct Sound {
    BGSSoundDescriptorForm* sound;
    Flag_a4a94b8a flags;
    float chance;
};
static_assert(sizeof(Sound) == 16, "Sound layout differs from the PDB");
