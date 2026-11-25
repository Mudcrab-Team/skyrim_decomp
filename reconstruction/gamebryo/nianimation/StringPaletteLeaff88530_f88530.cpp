// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf88530 StringPaletteLeaff88530::IsEqual
#include "StringPaletteLeaff88530_f88530.h"
#include <cstring>

bool StringPaletteLeaff88530::IsEqual(const StringPaletteLeaff88530* other) const
{
    if (!PaletteBasef88530::IsEqual(other)) {
        return false;
    }
    if (other->length != length || other->capacity != capacity) {
        return false;
    }
    if (length && std::memcmp(other->bytes, bytes, length) != 0) {
        return false;
    }
    return true;
}
