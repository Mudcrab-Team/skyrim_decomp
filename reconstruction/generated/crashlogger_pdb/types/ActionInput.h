// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActionInput; size 0x28
#pragma once

#include "NiPointer_RE__TESObjectREFR_e3263c8b.h"
struct ActionInput_vtbl;
struct BGSAction;
struct ActionInput {
    ActionInput_vtbl* __vftable;
    NiPointer_RE__TESObjectREFR_e3263c8b source;
    NiPointer_RE__TESObjectREFR_e3263c8b target;
    BGSAction* action;
    unsigned char priority_raw[8];
};
static_assert(sizeof(ActionInput) == 40, "ActionInput layout differs from the PDB");
