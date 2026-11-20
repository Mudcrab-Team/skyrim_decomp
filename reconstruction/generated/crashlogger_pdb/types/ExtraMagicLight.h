// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraMagicLight; size 0x18
#pragma once

#include "ExtraLight.h"
struct ExtraMagicLight {
    ExtraLight _base;
};
static_assert(sizeof(ExtraMagicLight) == 24, "ExtraMagicLight layout differs from the PDB");
