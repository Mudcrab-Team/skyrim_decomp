// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x1586fc0 BSParabolicCullingProcess::TestSphere
// CI hash: 0x1586fc0 ?TestSphere@BSParabolicCullingProcess@@QEAA_NAEBUNiBound@@@Z
#include "BSParabolicCullingProcess_1586fc0.h"

#include <math.h>

bool BSParabolicCullingProcess::TestSphere(const NiBound& bound)
{
    float dx = bound.center.x - lightPosition.x;
    float dy = bound.center.y - lightPosition.y;
    float dz = bound.center.z - lightPosition.z;

    if (sqrtf(dx * dx + dy * dy + dz * dz) - bound.radius - lightRadius < 0.0f) {
        float distance = equatorialPlane.normal.x * bound.center.x + equatorialPlane.normal.y * bound.center.y
                       + equatorialPlane.normal.z * bound.center.z - equatorialPlane.constant;
        if (distance - bound.radius < 0.0f)
            return true;
        int side = distance < 0.0f ? 2 : distance > 0.0f;
        return backHemisphereAccumulator != nullptr || side == 1;
    }
    return false;
}
