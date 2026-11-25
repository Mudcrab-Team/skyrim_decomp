// Source exposure: mixed (community names; pinned-image observations).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original partial declarations from observed field accesses.
// NiQuaternionInterpolator, Functionf85a50: GUESS(low); inventory owner and unnamed predicate
// QuaternionValue, invalidQuaternion, prefix, value, data: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

struct QuaternionValue
{
    float w, x, y, z;
};
extern const QuaternionValue invalidQuaternion;
class NiQuaternionInterpolator
{
public:
    bool Functionf85a50() const;
    std::uint8_t prefix[0x18];
    QuaternionValue value;
    void* data;
};
static_assert(offsetof(NiQuaternionInterpolator, value) == 0x18, "observed quaternion offset");
static_assert(offsetof(NiQuaternionInterpolator, data) == 0x28, "observed data offset");
