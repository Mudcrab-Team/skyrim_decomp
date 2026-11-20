// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCompoundFrustumOperator; size 0xc
#pragma once

#include "BSCompoundFrustumOperatorType.h"
struct BSCompoundFrustumOperator {
    BSCompoundFrustumOperatorType type;
    unsigned int onPass;
    unsigned int onFail;
};
static_assert(sizeof(BSCompoundFrustumOperator) == 12, "BSCompoundFrustumOperator layout differs from the PDB");
