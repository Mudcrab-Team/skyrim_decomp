// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, StartGroupIntersection: CRASHLOGGER_PDB(59818@2026.10.24)
// functionOperators, freeOp, BSCompoundFrustumOperatorType: CRASHLOGGER_PDB(59818@2026.10.24)
// FrustumOperatorArray, Grow: GUESS(low)
#pragma once

#include "generated/crashlogger_pdb/types/BSCompoundFrustumOperator.h"

struct FrustumOperatorArray
{
    void Grow(int size);
    BSCompoundFrustumOperator* data;
    unsigned char unknown08[8];
    int size;
    unsigned int unknown14;
};

class BSCompoundFrustum
{
public:
    void StartGroupIntersection();

private:
    unsigned char unknown00[0x18];
    FrustumOperatorArray functionOperators;
    unsigned char unknown30[0x8c];
    int freeOp;
};
