// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, AddPortalOpening: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xff7df0 BSCompoundFrustum::AddPortalOpening
#include "BSCompoundFrustum_ff7df0.h"

#include <cmath>

void BSCompoundFrustum::AddPortalOpening(BSPortal* portal)
{
    if (freeOp + 2 >= static_cast<int>(functionOperators.size)) {
        functionOperators.Resize(static_cast<int>(functionOperators.size) + 10);
    }
    if (freePlane + 1 >= static_cast<int>(planes.size)) {
        planes.Resize(static_cast<int>(planes.size) + 4);
    }

    NiPoint3 corners[4];
    portal->GetCorners(corners);
    NiPlane portalPlane(corners[0], corners[1], corners[2]);

    functionOperators[freeOp].type = BSCompoundFrustumOperatorType::kTestIntersects;
    ++freeOp;
    functionOperators[freeOp].planeIndex = freePlane;
    ++freeOp;

    portal->CopyFrustumPlanes(viewPosition, planes[freePlane]);
    if (std::fabs(portalPlane.SignedDistance(viewPosition)) > 5.0f) {
        planes[freePlane].activePlanes = 0x3Fu;
    } else {
        planes[freePlane].activePlanes = 0;
    }
    ++freePlane;
}
