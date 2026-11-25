// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf712c0 TransformDataLeaff712c0::CleanRotAnim
#include "TransformDataLeaff712c0_f712c0.h"

void TransformDataLeaff712c0::CleanRotAnim(RotationKey* keys, std::uint32_t, std::int32_t type)
{
    if (!keys) {
        return;
    }
    if (type == 4) {
        CleanEulerKeys(keys);
    }
    gRotationDeleteTable[rotationType](keys);
}
