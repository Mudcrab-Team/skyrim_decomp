// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, Reset: CRASHLOGGER_PDB(59818@2026.10.24)
// planes, functionOperators, viewPosition, camera, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded: CRASHLOGGER_PDB(59818@2026.10.24)
// niPointZero: GUESS(low)
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint3.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__NiFrustumPlanes_3b460d56.h"
#include "generated/crashlogger_pdb/types/BSTArray_BSCompoundFrustumOperator_c332d121.h"

class NiCamera;
extern const NiPoint3 niPointZero;

class BSCompoundFrustum
{
public:
    void Reset();

private:
    BSTArray_RE__NiFrustumPlanes_3b460d56 planes;
    BSTArray_BSCompoundFrustumOperator_c332d121 functionOperators;
    unsigned char unknown30[0x70];
    NiPoint3 viewPosition;
    NiCamera* camera;
    unsigned int freePlane;
    unsigned int freeOp;
    unsigned int firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};
