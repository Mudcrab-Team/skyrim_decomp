// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk563180: STANDIN GUESS(low)
// Unk563180::Function563180: GUESS(low)
// Unk563180::status, StatusView563180: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct StatusView563180 { virtual void Unknown0();
virtual void Unknown1();
virtual void Unknown2();
virtual void Unknown3();
virtual void Unknown4();
virtual std::uint8_t Query(); };

class Unk563180
{
public:
    bool Function563180();
    std::uint8_t unknown0[152];
    StatusView563180* status;
};
static_assert(offsetof(Unk563180, status) == 152, "field offset");
