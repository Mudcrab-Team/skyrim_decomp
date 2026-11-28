// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseComponent1ef670, Unit1ef670, CopyFrom1ef670, value: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BaseComponent1ef670
{
public:
    virtual ~BaseComponent1ef670();
};

class Unit1ef670 : public BaseComponent1ef670
{
public:
    void CopyFrom1ef670(BaseComponent1ef670* a_source);  // compared: 0x1ef670

    std::uint32_t value;  // 08
};
static_assert(offsetof(Unit1ef670, value) == 0x08, "Unit1ef670::value offset");
