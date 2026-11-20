// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpArrayAction; size 0x40
#pragma once

#include "hkArray_RE__hkpEntity_2da0ea3b.h"
#include "hkpAction_085cde55.h"
struct hkpArrayAction {
    hkpAction_085cde55 _base;
    hkArray_RE__hkpEntity_2da0ea3b entities;
};
static_assert(sizeof(hkpArrayAction) == 64, "hkpArrayAction layout differs from the PDB");
