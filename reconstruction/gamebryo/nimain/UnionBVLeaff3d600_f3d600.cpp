// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf3d600 UnionBVLeaff3d600::~UnionBVLeaff3d600
#include "UnionBVLeaff3d600_f3d600.h"

UnionBVBase::~UnionBVBase() = default;

UnionChildren::~UnionChildren()
{
    ReleaseUnionArray(items);
}

UnionBVLeaff3d600::~UnionBVLeaff3d600()
{
    RemoveChildren();
}
