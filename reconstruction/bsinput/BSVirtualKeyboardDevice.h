// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSVirtualKeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice, BSInputDevice, BSKeyboardDevice: STANDIN EXE_RTTI
// BSVirtualKeyboardDevice::Unk_09, BSVirtualKeyboardDevice::Unk_0A, BSVirtualKeyboardDevice::~BSVirtualKeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIInputDevice::~BSIInputDevice, unknown08: GUESS(low)
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

class BSKeyboardDevice : public BSInputDevice
{
public:
    virtual ~BSKeyboardDevice();  // declared only; the complete destructor is bound by hint to 0xe12630
};
static_assert(sizeof(BSKeyboardDevice) == 0x70, "BSKeyboardDevice size");

class BSVirtualKeyboardDevice : public BSKeyboardDevice
{
public:
    BSVirtualKeyboardDevice();
    virtual void Unk_09();  // compared: 0xe7c4b0
    virtual void Unk_0A();  // compared: 0xe7c4c0
    virtual ~BSVirtualKeyboardDevice() {}  // compared: 0xe7c4d0 (scalar deleting destructor; target inlines this destructor)
};
static_assert(sizeof(BSVirtualKeyboardDevice) == 0x70, "BSVirtualKeyboardDevice size");
