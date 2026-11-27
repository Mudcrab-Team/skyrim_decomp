// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Calendar: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Calendar::Function646020: GUESS(low)
// Calendar::value, GlobalValue646020, gFallback646020: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct GlobalValue646020 { std::uint8_t unknown00[52]; float value; };
extern float gFallback646020;
class Calendar
{
public:
    float Function646020();
    std::uint8_t unknown0[40];
    GlobalValue646020* value;
};
static_assert(offsetof(Calendar, value) == 40, "field offset");
