// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the axis-aligned bound copy.
// 0xfce820 BSMultiBoundAABB::CopyMembers
#include "BSMultiBoundAABB_fce820.h"

void CopyShapeMembers(const BSMultiBoundShape* source, BSMultiBoundShape* target);

void BSMultiBoundAABB::CopyMembers(BSMultiBoundAABB* target) const
{
    CopyShapeMembers(this, target);
    target->SetCenter(center);
    target->halfExtents.x = halfExtents.x;
    target->halfExtents.y = halfExtents.y;
    target->halfExtents.z = halfExtents.z;
}
