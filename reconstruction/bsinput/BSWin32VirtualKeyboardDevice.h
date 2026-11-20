// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWin32VirtualKeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice, BSInputDevice, BSKeyboardDevice, BSVirtualKeyboardDevice: STANDIN EXE_RTTI
// BSWin32VirtualKeyboardDevice::Initialize, BSWin32VirtualKeyboardDevice::Release, BSWin32VirtualKeyboardDevice::Reset: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIInputDevice::~BSIInputDevice, unknown08: GUESS(low)
// BSWin32VirtualKeyboardDevice::~BSWin32VirtualKeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSVirtualKeyboardDevice::~BSVirtualKeyboardDevice: GUESS(low)
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
};
static_assert(sizeof(BSKeyboardDevice) == 0x70, "BSKeyboardDevice size");

class BSVirtualKeyboardDevice : public BSKeyboardDevice
{
public:
    // Declared only; the compared deleting destructor calls it, bound by address.
    virtual ~BSVirtualKeyboardDevice();
};
static_assert(sizeof(BSVirtualKeyboardDevice) == 0x70, "BSVirtualKeyboardDevice size");

class BSWin32VirtualKeyboardDevice : public BSVirtualKeyboardDevice
{
public:
    virtual ~BSWin32VirtualKeyboardDevice();
    virtual void Initialize();  // compared: 0xe12e60
    virtual void Release();  // compared: 0xe12e70
    virtual void Reset();  // compared: 0xe12e80
};
static_assert(sizeof(BSWin32VirtualKeyboardDevice) == 0x70, "BSWin32VirtualKeyboardDevice size");
