// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFurnitureEvent; size 0x18
#pragma once

#include "NiPointer_RE__TESObjectREFR_e3263c8b.h"
struct TESFurnitureEvent {
    NiPointer_RE__TESObjectREFR_e3263c8b actor;
    NiPointer_RE__TESObjectREFR_e3263c8b targetFurniture;
    unsigned char type_raw[8];
};
static_assert(sizeof(TESFurnitureEvent) == 24, "TESFurnitureEvent layout differs from the PDB");
