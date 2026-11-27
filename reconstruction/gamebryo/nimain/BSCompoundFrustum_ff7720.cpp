// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, Reset: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff7720 BSCompoundFrustum::Reset
#include "BSCompoundFrustum_ff7720.h"

void BSCompoundFrustum::Reset()
{
    freePlane = 0;
    freeOp = 0;
    viewPosition.x = niPointZero.x;
    viewPosition.y = niPointZero.y;
    viewPosition.z = niPointZero.z;
    if (planes._data) {
        planes._size = 0;
    }
    if (functionOperators._data) {
        functionOperators._size = 0;
    }
    skipViewFrustum = false;
    prethreaded = false;
    firstOp = 0;
    camera = nullptr;
}
