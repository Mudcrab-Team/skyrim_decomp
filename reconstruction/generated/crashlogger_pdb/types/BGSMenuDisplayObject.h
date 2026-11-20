// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMenuDisplayObject; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct TESBoundObject_fc790793;
struct BGSMenuDisplayObject {
    BaseFormComponent _base;
    TESBoundObject_fc790793* menuDispObject;
};
static_assert(sizeof(BGSMenuDisplayObject) == 16, "BGSMenuDisplayObject layout differs from the PDB");
