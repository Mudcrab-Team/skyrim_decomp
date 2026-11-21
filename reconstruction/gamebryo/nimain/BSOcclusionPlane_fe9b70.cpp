// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction from the two endpoint-group checks.
// 0xfe9b70 BSOcclusionPlane::Functionfe9b70
#include "BSOcclusionPlane_fe9b70.h"

std::uint32_t BSOcclusionPlane::Functionfe9b70() const
{
    if (endpoint00 || endpoint02) {
        return 2;
    }
    if (endpoint01 || endpoint03) {
        return 1;
    }
    return 0;
}
