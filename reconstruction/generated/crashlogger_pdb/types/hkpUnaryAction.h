// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpUnaryAction; size 0x38
#pragma once

#include "hkpAction_085cde55.h"
struct hkpEntity;
struct hkpUnaryAction {
    hkpAction_085cde55 _base;
    hkpEntity* entity;
};
static_assert(sizeof(hkpUnaryAction) == 56, "hkpUnaryAction layout differs from the PDB");
