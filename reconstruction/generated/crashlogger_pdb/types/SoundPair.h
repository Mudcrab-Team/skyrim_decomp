// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SoundPair; size 0x10
#pragma once

#include "SoundID.h"
struct BGSSoundDescriptorForm;
struct SoundPair {
    SoundID id;
    unsigned int pad04;
    BGSSoundDescriptorForm* sound;
};
static_assert(sizeof(SoundPair) == 16, "SoundPair layout differs from the PDB");
