// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Directional; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "MaxMin_RE__Color_3faaad1b.h"
struct Directional {
    MaxMin_RE__Color_3faaad1b x;
    MaxMin_RE__Color_3faaad1b y;
    MaxMin_RE__Color_3faaad1b z;
};
static_assert(sizeof(Directional) == 24, "Directional layout differs from the PDB");
