// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFogProperty; size 0x50
#pragma once

#include "NiColor_e5e1ad7d.h"
#include "NiProperty_29cbd083.h"
struct NiFogProperty {
    NiProperty_29cbd083 _base;
    unsigned int unk30;
    float unk34;
    NiColor_e5e1ad7d nearColor;
    NiColor_e5e1ad7d farColor;
};
static_assert(sizeof(NiFogProperty) == 80, "NiFogProperty layout differs from the PDB");
