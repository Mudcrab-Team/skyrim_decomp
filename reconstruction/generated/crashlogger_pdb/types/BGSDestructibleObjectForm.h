// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDestructibleObjectForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct DestructibleObjectData;
struct BGSDestructibleObjectForm {
    BaseFormComponent _base;
    DestructibleObjectData* data;
};
static_assert(sizeof(BGSDestructibleObjectForm) == 16, "BGSDestructibleObjectForm layout differs from the PDB");
