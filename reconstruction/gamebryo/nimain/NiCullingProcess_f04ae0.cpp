// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xf04ae0 NiCullingProcess::Process1
#include "NiCullingProcess_f04ae0.h"

void NiCullingProcess::Process1(NiAVObject* object, std::uint32_t alphaGroupIndex)
{
    const std::uint32_t objFlags = object->flags;
    if (TestBit(objFlags, 12) && !ignorePreprocess) {
        if (!TestBit(objFlags, 20)) {
            object->OnVisible(this, alphaGroupIndex);
        }
        return;
    }

    if (!TestBit(objFlags, 11)) {
        const std::uint32_t savedPlanes = planes.activePlanes;
        if (savedPlanes != 0) {
            if (object->worldBound.radiusRaw == 0) {
                return;
            }

            std::uint32_t planeIndex = 0;
            std::uint32_t bit = 1u;
            // Rotate single-bit mask across the six frustum planes.
            for (; planeIndex < 6; ++planeIndex, bit = _rotl(bit, 1)) {
                if ((planes.activePlanes & bit) != 0) {
                    const NiPlane& plane = planes.cullingPlanes[planeIndex];
                    const float distance =
                        plane.normal.x * object->worldBound.center.x +
                        plane.normal.y * object->worldBound.center.y +
                        plane.normal.z * object->worldBound.center.z -
                        plane.constant;
                    if (!(distance > -object->worldBound.radius)) {
                        break;
                    }
                    if (distance >= object->worldBound.radius && enablePlaneOptimization) {
                        planes.activePlanes &= ~bit;
                    }
                }
            }

            if (planeIndex == 6) {
                object->OnVisible(this, 0xFFFFFFFFu);
                if (updateAccumulateFlag) {
                    object->flags |= kAccumulated;
                }
                planes.activePlanes = savedPlanes;
                return;
            }
            if (updateAccumulateFlag) {
                object->flags &= ~kAccumulated;
            }
            planes.activePlanes = savedPlanes;
            return;
        }
    }

    object->OnVisible(this, alphaGroupIndex);
}
