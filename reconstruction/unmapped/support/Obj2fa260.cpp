// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2fa260 Obj2fa260::GetGlobalVec
// Adapted bodies: none
#include "Obj2fa260.h"

// Guess: return a copy of the global 3D vector by value.
Vec2fa260 Obj2fa260::GetGlobalVec() const
{
    return Vec2fa260(gVec2fa260.m_x, gVec2fa260.m_y, gVec2fa260.m_z);
}
