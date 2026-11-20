// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxCharacterDef; size 0x20
#pragma once

#include "GFxResource.h"
#include "GFxResourceID.h"
struct GFxCharacterDef {
    GFxResource _base;
    GFxResourceID resourceId;
    unsigned int pad1C;
};
static_assert(sizeof(GFxCharacterDef) == 32, "GFxCharacterDef layout differs from the PDB");
