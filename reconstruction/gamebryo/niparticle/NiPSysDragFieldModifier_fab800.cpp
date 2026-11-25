// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfab800 NiPSysDragFieldModifier::CopyMembers
#include "NiPSysDragFieldModifier_fab800.h"

void NiPSysDragFieldModifier::CopyMembers(NiPSysDragFieldModifier* destination, NiCloningProcess& process)
{
    DragFieldBase::CopyMembers(destination, process);
    destination->usesDirection = usesDirection;
    destination->direction.x = direction.x;
    destination->direction.y = direction.y;
    destination->direction.z = direction.z;
}
