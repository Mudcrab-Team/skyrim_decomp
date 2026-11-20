// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESContainer; size 0x18
#pragma once

#include "BaseFormComponent.h"
struct ContainerObject;
struct TESContainer {
    BaseFormComponent _base;
    ContainerObject** containerObjects;
    unsigned int numContainerObjects;
    bool allowStolenItems;
    unsigned char undefined_15[3];
};
static_assert(sizeof(TESContainer) == 24, "TESContainer layout differs from the PDB");
