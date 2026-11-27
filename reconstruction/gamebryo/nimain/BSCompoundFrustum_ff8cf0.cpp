// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, PrependIntersectionGroupStart: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff8cf0 BSCompoundFrustum::PrependIntersectionGroupStart
#include "BSCompoundFrustum_ff8cf0.h"

void BSCompoundFrustum::PrependIntersectionGroupStart()
{
    bool needPrepend = true;
    if (functionOperators[0].type == BSCompoundFrustumOperatorType::kGroupIntersection) {
        int depth = 1;
        int index = 1;
        while (depth > 0 && index < freeOp) {
            switch (functionOperators[index].type) {
            case BSCompoundFrustumOperatorType::kGroupIntersection:
            case BSCompoundFrustumOperatorType::kGroupUnion:
                ++depth;
                break;
            case BSCompoundFrustumOperatorType::kGroupEnd:
                --depth;
                break;
            default:
                break;
            }
            ++index;
        }
        if (index == freeOp && depth == 0) {
            needPrepend = false;
        }
    }

    if (needPrepend) {
        if (freeOp + 1 >= static_cast<int>(functionOperators.size)) {
            functionOperators.Resize(static_cast<int>(functionOperators.size) + 10);
        }
        ShiftOperators(1, false);
        functionOperators[0].type = BSCompoundFrustumOperatorType::kGroupIntersection;
    } else {
        --freeOp;
    }
}
