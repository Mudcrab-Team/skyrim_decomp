// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, AddOcclusionBox: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff86d0 BSCompoundFrustum::AddOcclusionBox
#include "BSCompoundFrustum_ff86d0.h"

bool BSCompoundFrustum::AddOcclusionBox(BSOcclusionBox* box)
{
    if (freePlane + 2 >= static_cast<int>(planes.size)) {
        planes.Resize(static_cast<int>(planes.size) + 4);
    }

    bool added = box->CopyFrustumPlanes(camera, planes[freePlane], planes[freePlane + 1]);
    if (added) {
        if (freeOp + 6 >= static_cast<int>(functionOperators.size)) {
            functionOperators.Resize(static_cast<int>(functionOperators.size) + 10);
        }

        functionOperators[freeOp].type = BSCompoundFrustumOperatorType::kGroupUnion;
        ++freeOp;
        functionOperators[freeOp].type = BSCompoundFrustumOperatorType::kTestInside;
        ++freeOp;
        functionOperators[freeOp].planeIndex = freePlane;
        ++freeOp;
        functionOperators[freeOp].type = BSCompoundFrustumOperatorType::kTestInside;
        ++freeOp;
        functionOperators[freeOp].planeIndex = freePlane + 1;
        ++freeOp;
        functionOperators[freeOp].type = BSCompoundFrustumOperatorType::kGroupEnd;
        ++freeOp;
        freePlane += 2;
    }

    return added;
}
