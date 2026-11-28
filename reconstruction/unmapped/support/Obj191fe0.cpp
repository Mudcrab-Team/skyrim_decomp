// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x191fe0 Obj191fe0::IsNotEqual
// Adapted bodies: none.
#include "Obj191fe0.h"

// Compares handle, six float fields, and trailing byte against a_other for inequality.
bool Obj191fe0::IsNotEqual(const Obj191fe0* a_other) const
{
    if (handle != a_other->handle) {
        return true;
    }
    if (unk04 != a_other->unk04) {
        return true;
    }
    if (unk08 != a_other->unk08) {
        return true;
    }
    if (unk0C != a_other->unk0C) {
        return true;
    }
    if (unk10 != a_other->unk10) {
        return true;
    }
    if (unk14 != a_other->unk14) {
        return true;
    }
    if (unk18 != a_other->unk18) {
        return true;
    }
    if (unk1C != a_other->unk1C) {
        return true;
    }
    return false;
}
