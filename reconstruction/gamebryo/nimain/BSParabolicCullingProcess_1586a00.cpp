// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x1586a00 BSParabolicCullingProcess::Process1
#include "BSParabolicCullingProcess_1586a00.h"

void BSParabolicCullingProcess::Process1(NiAVObject* object, std::uint32_t alphaGroupIndex)
{
    const BSCPCullingType mode = cullMode;
    if (mode != BSCPCullingType::kAllPass && mode != BSCPCullingType::kAllFail) {
        const std::uint32_t objFlags = object->flags;
        if (TestBit(objFlags, 12) && !ignorePreprocess) {
            if (!TestBit(objFlags, 20)) {
                object->OnVisible(this, alphaGroupIndex);
                if (updateAccumulateFlag) {
                    object->flags |= kAccumulated;
                }
            } else if (updateAccumulateFlag) {
                object->flags = objFlags & ~kAccumulated;
            }
            return;
        }

        if (compoundFrustum && compoundFrustum->freeOp != 0 &&
            mode != BSCPCullingType::kIgnoreMultiBounds) {
            if (TestBit(objFlags, 11)) {
                object->OnVisible(this, alphaGroupIndex);
                if (updateAccumulateFlag) {
                    object->flags |= kAccumulated;
                }
                return;
            }

            std::uint32_t planeState[256];
            compoundFrustum->GetActivePlaneState(planeState, 256);

            BSCompoundFrustum* frustum = compoundFrustum;
            if (frustum->skipViewFrustum) {
                if (frustum->Process(object)) {
                    ProcessHemisphere(object, alphaGroupIndex);
                }
            } else {
                const std::uint32_t mask = GetHemisphereMask(&object->worldBound);
                if (mask != 0 && frustum->Process(object)) {
                    alphaGroupStopIndex = mask;
                    object->OnVisible(this, alphaGroupIndex);
                    if (updateAccumulateFlag) {
                        object->flags |= kAccumulated;
                    }
                } else if (updateAccumulateFlag) {
                    object->flags &= ~kAccumulated;
                }
            }

            compoundFrustum->SetActivePlaneState(planeState, 256);
            return;
        }

        if (TestBit(objFlags, 11)) {
            object->OnVisible(this, alphaGroupIndex);
            if (updateAccumulateFlag) {
                object->flags |= kAccumulated;
            }
            return;
        }

        ProcessHemisphere(object, alphaGroupIndex);
        return;
    }

    if (mode == BSCPCullingType::kAllPass) {
        object->OnVisible(this, alphaGroupIndex);
        if (updateAccumulateFlag) {
            object->flags |= kAccumulated;
        }
    } else if (updateAccumulateFlag) {
        object->flags &= ~kAccumulated;
    }
}
