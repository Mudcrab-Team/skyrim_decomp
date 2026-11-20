// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPSysModifier; size 0x30
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiObject_de5bc370.h"
#include "ORDER.h"
struct NiParticleSystem;
struct NiPSysModifier {
    NiObject_de5bc370 _base;
    BSFixedString_char_83b572b4 name;
    ORDER order;
    unsigned int pad1C;
    NiParticleSystem* target;
    bool active;
    unsigned char pad29;
    unsigned short pad2A;
    unsigned int pad2C;
};
static_assert(sizeof(NiPSysModifier) == 48, "NiPSysModifier layout differs from the PDB");
