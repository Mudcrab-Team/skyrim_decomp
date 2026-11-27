// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, StartGroupIntersection: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff7ce0 BSCompoundFrustum::StartGroupIntersection
#include "BSCompoundFrustum_ff7ce0.h"

void BSCompoundFrustum::StartGroupIntersection()
{
    if (freeOp + 1 >= functionOperators.size) {
        functionOperators.Grow(functionOperators.size + 10);
    }
    functionOperators.data[static_cast<unsigned int>(freeOp)].type =
        BSCompoundFrustumOperatorType::kGroupIntersection;
    ++freeOp;
}
