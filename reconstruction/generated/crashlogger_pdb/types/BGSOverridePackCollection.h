// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSOverridePackCollection; size 0x28
#pragma once

#include "BaseFormComponent.h"
struct BGSListForm;
struct BGSOverridePackCollection {
    BaseFormComponent _base;
    BGSListForm* spectatorOverRidePackList;
    BGSListForm* observeCorpseOverRidePackList;
    BGSListForm* guardWarnOverRidePackList;
    BGSListForm* enterCombatOverRidePackList;
};
static_assert(sizeof(BGSOverridePackCollection) == 40, "BGSOverridePackCollection layout differs from the PDB");
