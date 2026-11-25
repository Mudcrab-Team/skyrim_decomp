// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf3c270 SphereBVLeaff3c270::operator==
// CI hash: 0xf3c270 ??8SphereBVLeaff3c270@@QEBA_NAEBUBoundingVolumeLeaf@@@Z
#include "SphereBVLeaff3c270_f3c270.h"

bool SphereBVLeaff3c270::operator==(const BoundingVolumeLeaf& other) const
{
    if (other.table->type(&other) == 0 &&
        static_cast<const SphereBVLeaff3c270&>(other).sphere == sphere) {
        return true;
    }
    return false;
}
