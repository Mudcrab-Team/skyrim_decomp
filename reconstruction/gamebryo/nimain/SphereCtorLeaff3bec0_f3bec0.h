// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiSphereBV: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types, fields and global: GUESS(low); used offsets observed on the target
#pragma once

struct SphereCtorPoint { float x, y, z; };
extern SphereCtorPoint gSphereDefault;
struct SphereCtorPayload
{
    SphereCtorPayload();
    SphereCtorPoint center;
    float radius;
};
class SphereCtorLeaff3bec0
{
public:
    SphereCtorLeaff3bec0(float radius, const SphereCtorPoint& center);
    virtual ~SphereCtorLeaff3bec0();
    SphereCtorPayload sphere;
};
