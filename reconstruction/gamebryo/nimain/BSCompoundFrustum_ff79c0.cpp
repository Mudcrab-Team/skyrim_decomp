// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, ProcessPortal: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff79c0 BSCompoundFrustum::ProcessPortal
#include "BSCompoundFrustum_ff79c0.h"

bool BSCompoundFrustum::ProcessPortal(BSPortal* portal)
{
    if (freeOp > 0) {
        unsigned int currentOp = firstOp;
        while (functionOperators[currentOp].type != BSCompoundFrustumOperatorType::kAccept &&
               functionOperators[currentOp].type != BSCompoundFrustumOperatorType::kReject) {
            bool passed = false;
            switch (functionOperators[currentOp].type) {
            case BSCompoundFrustumOperatorType::kTestIntersects:
                passed = portal->IntersectsPlanes(
                    planes[functionOperators[currentOp + 1].planeIndex],
                    false,
                    NiPoint3Constants::ZERO);
                break;
            case BSCompoundFrustumOperatorType::kTestInside:
                passed = !portal->InsidePlanes(planes[functionOperators[currentOp + 1].planeIndex]);
                break;
            default:
                break;
            }
            currentOp = passed ? functionOperators[currentOp].onPass : functionOperators[currentOp].onFail;
        }

        return functionOperators[currentOp].type == BSCompoundFrustumOperatorType::kAccept;
    }

    return true;
}
