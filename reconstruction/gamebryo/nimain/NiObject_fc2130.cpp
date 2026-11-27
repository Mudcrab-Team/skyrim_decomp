// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Functionfc2130Object: GUESS(low)
// 0xfc2130 Functionfc2130Object::Functionfc2130Object
#include "NiObject_fc2130.h"

// Construct the NiObject subclass with parameters, default origin, and zeroed fields.
Functionfc2130Object::Functionfc2130Object(float a_value, bool a_flag1, bool a_flag2, void* a_ptr) :
    NiObject(),
    unk10(a_value),
    unk14(a_flag1),
    unk15(a_flag2),
    unk18(a_ptr),
    origin(g_defaultOrigin),
    unk2C(0),
    unk30(0),
    unk38(0)
{
}
