// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff70f0 BSCompoundFrustum::BSCompoundFrustum
#include "BSCompoundFrustum_ff70f0.h"

BSCompoundFrustum::BSCompoundFrustum()
    : freePlane(0)
    , freeOp(0)
{
    viewPosition.x = NiPoint3Constants::ZERO.x;
    viewPosition.y = NiPoint3Constants::ZERO.y;
    viewPosition.z = NiPoint3Constants::ZERO.z;
    planes.ResizeConstructed(4);
    functionOperators.ResizeTrivial(10);
    skipViewFrustum = false;
    prethreaded = false;
    firstOp = 0;
    camera = nullptr;
}
