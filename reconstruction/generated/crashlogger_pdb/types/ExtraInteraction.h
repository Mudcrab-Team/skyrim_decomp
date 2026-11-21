// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraInteraction; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTSmartPointer_RE__RefrInteraction_c967d209.h"
struct ExtraInteraction {
    BSExtraData_4ca6af76 _base;
    BSTSmartPointer_RE__RefrInteraction_c967d209 interaction;
};
static_assert(sizeof(ExtraInteraction) == 24, "ExtraInteraction layout differs from the PDB");
