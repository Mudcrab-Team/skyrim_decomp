// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xef8d30 NiQuaternion::UnitInverse
#include "NiQuaternion_ef8d30.h"

NiQuaternion NiQuaternion::UnitInverse(const NiQuaternion& rotation)
{
    NiQuaternion result;
    result.w = rotation.w;
    result.x = -rotation.x;
    result.y = -rotation.y;
    result.z = -rotation.z;
    return result;
}
