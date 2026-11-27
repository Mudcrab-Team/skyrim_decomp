// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ShiftOperators: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff8a60 BSCompoundFrustum::ShiftOperators
#include "BSCompoundFrustum_ff8a60.h"

void BSCompoundFrustum::ShiftOperators(int shift, bool clearVacated)
{
    if (shift > 0) {
        if (freeOp + shift >= static_cast<int>(functionOperators.size)) {
            int grow = shift > 10 ? shift : 10;
            functionOperators.Resize(static_cast<int>(functionOperators.size) + grow);
        }

        int index = freeOp + shift - 1;
        for (; index >= shift; --index) {
            functionOperators[index].type = functionOperators[index - shift].type;
        }
        if (clearVacated) {
            for (; index > 0; --index) {
                functionOperators[index].type = BSCompoundFrustumOperatorType::kNone;
            }
        }
        freeOp += shift;
    } else if (shift < 0) {
        int count = -shift;
        if (freeOp > count) {
            for (int index = 0; index < freeOp - count; ++index) {
                functionOperators[index].type = functionOperators[index + count].type;
            }
            freeOp -= count;
        } else {
            freeOp = 0;
        }
    }
}
