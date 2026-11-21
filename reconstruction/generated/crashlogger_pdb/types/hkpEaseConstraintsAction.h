// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEaseConstraintsAction; size 0x68
#pragma once

#include "hkArray_RE__hkpConstraintInstance_8fa29619.h"
#include "hkArray_float_2ea7b9d8.h"
#include "hkpArrayAction.h"
struct hkpEaseConstraintsAction {
    hkpArrayAction _base;
    float duration;
    float timePassed;
    hkArray_RE__hkpConstraintInstance_8fa29619 originalConstraints;
    hkArray_float_2ea7b9d8 originalLimits;
};
static_assert(sizeof(hkpEaseConstraintsAction) == 104, "hkpEaseConstraintsAction layout differs from the PDB");
