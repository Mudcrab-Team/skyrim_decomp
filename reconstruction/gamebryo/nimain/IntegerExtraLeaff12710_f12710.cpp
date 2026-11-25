// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf12710 IntegerExtraLeaff12710::IsEqual
#include "IntegerExtraLeaff12710_f12710.h"

bool IntegerExtraLeaff12710::IsEqual(const IntegerExtraLeaff12710* other) const
{
    if (!other || count != other->count) {
        return false;
    }
    if (values) {
        if (!other->values) {
            return false;
        }
        for (std::uint32_t index = 0; index < count; ++index) {
            if (values[index] != other->values[index]) {
                return false;
            }
        }
    } else if (other->values) {
        return false;
    }
    return true;
}
