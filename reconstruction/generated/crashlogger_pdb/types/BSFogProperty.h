// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFogProperty; size 0x90
#pragma once

#include "NiFogProperty.h"
struct BSFogProperty {
    NiFogProperty _base;
    float nearDistance;
    float farDistance;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned long long unk60;
    unsigned long long unk68;
    unsigned long long unk70;
    unsigned long long unk78;
    float unk80;
    float power;
    float clamp;
    unsigned int pad8C;
};
static_assert(sizeof(BSFogProperty) == 144, "BSFogProperty layout differs from the PDB");
