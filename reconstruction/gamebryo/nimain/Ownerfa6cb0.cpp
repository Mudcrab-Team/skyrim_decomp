// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1002480 (gamebryo/nimain/BSMultiBoundAABB_1002480): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0xfa6cb0 Ownerfa6cb0::Functionfa6cb0
#include "Ownerfa6cb0.h"

// guess: same compiled code as matched 0x1002480 apart from relocated fields; its role here is not established.
void Ownerfa6cb0::Functionfa6cb0(Ownerfa6cb0* a_dest, NiCloningProcess& a_process)
{
    BSMultiBoundShape::CopyMembers(a_dest, a_process);
    a_dest->PointA.x = PointA.x;
    a_dest->PointA.y = PointA.y;
    a_dest->PointA.z = PointA.z;
    a_dest->PointB.x = PointB.x;
    a_dest->PointB.y = PointB.y;
    a_dest->PointB.z = PointB.z;
    a_dest->Radius = Radius;
}
