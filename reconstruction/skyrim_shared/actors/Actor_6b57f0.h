// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::GetPositionOrZero6b57f0, Vec3, x, y, z: GUESS(low); the class is the placeholder owner
#pragma once

struct Vec3
{
    float x;
    float y;
    float z;
};

class Actor
{
public:
    void GetPositionOrZero6b57f0(Vec3* out) const;
};
