// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf3bec0 SphereCtorLeaff3bec0::SphereCtorLeaff3bec0
#include "SphereCtorLeaff3bec0_f3bec0.h"

SphereCtorPayload::SphereCtorPayload()
{
    center.x = gSphereDefault.x;
    center.y = gSphereDefault.y;
    center.z = gSphereDefault.z;
    radius = 0.0f;
}

SphereCtorLeaff3bec0::SphereCtorLeaff3bec0(float radius, const SphereCtorPoint& center)
{
    sphere.center.x = center.x;
    sphere.center.y = center.y;
    sphere.center.z = center.z;
    sphere.radius = radius;
}
