// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ContainerItemExtra; size 0x18
#pragma once

#include "Conditional.h"
struct TESForm;
struct ContainerItemExtra {
    TESForm* owner;
    Conditional conditional;
    float healthMult;
    unsigned int pad14;
};
static_assert(sizeof(ContainerItemExtra) == 24, "ContainerItemExtra layout differs from the PDB");
