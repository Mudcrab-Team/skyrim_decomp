// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMouseDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice, BSInputDevice: STANDIN EXE_RTTI
// BSMouseDevice::Reinitialize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIInputDevice::~BSIInputDevice, unknown08, unknown70: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSIInputDevice
{
public:
    virtual ~BSIInputDevice() = default;
};
static_assert(sizeof(BSIInputDevice) == 0x8, "BSIInputDevice size");

class BSInputDevice : public BSIInputDevice
{
public:
    std::uint8_t unknown08[0x68];  // 08
};
static_assert(sizeof(BSInputDevice) == 0x70, "BSInputDevice size");

class BSMouseDevice : public BSInputDevice
{
public:
    virtual void Reinitialize();  // compared: 0xe13070

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown70[0x8];  // 70
};
static_assert(sizeof(BSMouseDevice) == 0x78, "BSMouseDevice size");
