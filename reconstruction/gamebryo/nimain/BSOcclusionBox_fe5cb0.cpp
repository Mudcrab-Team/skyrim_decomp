// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of box state copying and frustum output.
// 0xfe5cb0 BSOcclusionBox::CopyMembers
// 0xfe6d30 BSOcclusionBox::CopyPlaneSets
#include "BSOcclusionBox_fe5cb0.h"

void BSOcclusionBox::CopyMembers(BSOcclusionBox& destination, NiCloningProcess& cloning) const
{
    BSOcclusionShape::CopyMembers(destination, cloning);
    destination.size.x = size.x;
    destination.size.y = size.y;
    destination.size.z = size.z;
    destination.updateFacesOrVertices = true;
}

bool BSOcclusionBox::CopyPlaneSets(const NiAVObject& viewpoint, NiFrustumPlanes& first, NiFrustumPlanes& second)
{
    const bool rebuilt = RebuildPlaneSets(viewpoint);
    first.CopyFrom(frustumPlanes[0]);
    second.CopyFrom(frustumPlanes[1]);
    return rebuilt;
}
