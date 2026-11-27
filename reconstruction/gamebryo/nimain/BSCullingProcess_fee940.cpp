// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfee940 BSCullingProcess::TestBaseVisibility3
// CI hash: 0xfee940 ?TestBaseVisibility3@BSCullingProcess@@QEAA_NAEBUNiBound@@@Z
#include "BSCullingProcess_fee940.h"

bool BSCullingProcess::TestBaseVisibility3(const NiBound& bound)
{
    bool visible = true;
    for (unsigned int i = 0; i < 6 && visible; ++i) {
        unsigned int mask = 1u << i;
        if (!(activePlanes & mask))
            continue;
        const NiPlane& plane = planes[i];
        float distance = plane.normal.x * bound.center.x + plane.normal.y * bound.center.y
                       + plane.normal.z * bound.center.z - plane.constant;
        int side = !(distance > -bound.radius) ? 2 : distance >= bound.radius ? 1 : 0;
        visible = side != 2;
        if (side == 1 && enablePlaneOptimization)
            activePlanes &= ~mask;
    }
    return visible;
}
