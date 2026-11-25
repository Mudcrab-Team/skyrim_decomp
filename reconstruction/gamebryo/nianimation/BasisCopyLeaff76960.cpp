// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf76960 BasisCopyLeaff76960::CopyMembers
#include "BasisCopyLeaff76960.h"

void BasisCopyLeaff76960::CopyMembers(BasisCopyLeaff76960* destination, NiCloningProcess& process)
{
    BasisCopyBase::CopyMembers(destination, process);
    destination->basis = basis;
}
