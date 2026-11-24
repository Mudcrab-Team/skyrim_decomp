// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf60d90 FloatDataLeaff60d90::SetAnim
#include "FloatDataLeaff60d90_f60d90.h"

void FloatDataLeaff60d90::SetAnim(FloatKeyLeaf* newKeys, std::uint32_t newCount, std::int32_t newType)
{
    if (newKeys && newCount && newType) {
        keySize = gFloatKeySizes[newType];
        count = newCount;
        keys = newKeys;
        type = newType;
    } else {
        keySize = 0;
        count = 0;
        keys = nullptr;
        type = 0;
    }
}
