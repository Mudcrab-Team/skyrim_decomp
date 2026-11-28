// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Vec2fa260, gVec2fa260, Obj2fa260, Obj2fa260::GetGlobalVec: GUESS(low)
#pragma once

struct Vec2fa260
{
    Vec2fa260(float a_x, float a_y, float a_z) : m_x(a_x), m_y(a_y), m_z(a_z) {}

    float m_x;  // 0x00
    float m_y;  // 0x04
    float m_z;  // 0x08
};

extern Vec2fa260 gVec2fa260;

class Obj2fa260
{
public:
    Vec2fa260 GetGlobalVec() const;
};
