// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSInputDeviceManager: STANDIN GUESS(low)
// BSInputDeviceManager::Functioncf9840: GUESS(low)
// BSInputDeviceManager::device, InputDeviceViewcf9840: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// InputDeviceViewcf9840: STANDIN GUESS(low); observed interface prefix.
struct InputDeviceViewcf9840 { virtual void Unknown0();
virtual void Unknown1();
virtual void Unknown2();
virtual void Unknown3();
virtual void Unknown4();
virtual void Unknown5();
virtual void Unknown6();
virtual std::uint8_t Query(); };

class BSInputDeviceManager
{
public:
    bool Functioncf9840();
    std::uint8_t unknown0[112];
    InputDeviceViewcf9840* device;
};
static_assert(offsetof(BSInputDeviceManager, device) == 112, "field offset");
