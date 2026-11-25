// Source exposure: mixed (local binary analysis and named community declarations).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundSphere, NiPoint3, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetPointWithin, center, radius: SYMBOLS(fo4-pdb); method association inferred from distance test
// unknownPrefix: GUESS(low); unaccessed base storage, not a complete base declaration
#pragma once
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class BSMultiBoundSphere
{
public:
    bool GetPointWithin(const NiPoint3& point) const;
    unsigned char unknownPrefix[0x18];
    NiPoint3 center;
    float radius;
};
static_assert(offsetof(BSMultiBoundSphere, center) == 0x18, "center offset");
static_assert(offsetof(BSMultiBoundSphere, radius) == 0x24, "radius offset");
