// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Annotation; size 0x10
#pragma once

#include "hkStringPtr_33d8e88b.h"
struct Annotation {
    float time;
    unsigned int pad04;
    hkStringPtr_33d8e88b text;
};
static_assert(sizeof(Annotation) == 16, "Annotation layout differs from the PDB");
