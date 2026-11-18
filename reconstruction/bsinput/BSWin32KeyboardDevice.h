// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BSWin32KeyboardDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice, BSInputDevice, BSKeyboardDevice: STANDIN EXE_RTTI
// BSWin32KeyboardDevice::Unk_09, BSWin32KeyboardDevice::Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIInputDevice::~BSIInputDevice: GUESS(low)
// BSWin32KeyboardDevice::Reset, BSWin32KeyboardDevice::Release, BSDirectInputManager::ReleaseDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// g_directInputManager: GUESS(low); global pointer at address 0x32309d0, the manager the device is released through
// device: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); member at 0x70 as declared there
// keyState: GUESS(low); the key state buffer at 0x168, cleared as a whole by the compared body
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68: GUESS(low); storage not read by the compared code
// unk78, unk80, unk88, unk90, unk98, unkA0, unkA8, unkB0, unkB8, unkC0, unkC8, unkD0, unkD8, unkE0, unkE8, unkF0, unkF8, unk100, unk108, unk110, unk118, unk120, unk128, unk130, unk138, unk140, unk148, unk150, unk158, unk160: GUESS(low); storage not read by the compared code
// unk368: GUESS(low); storage not read by the compared code
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
    std::uint64_t unk08;  // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
    std::uint64_t unk20;  // 20
    std::uint64_t unk28;  // 28
    std::uint64_t unk30;  // 30
    std::uint64_t unk38;  // 38
    std::uint64_t unk40;  // 40
    std::uint64_t unk48;  // 48
    std::uint64_t unk50;  // 50
    std::uint64_t unk58;  // 58
    std::uint64_t unk60;  // 60
    std::uint64_t unk68;  // 68
};
static_assert(sizeof(BSInputDevice) == 0x70, "BSInputDevice size");

class BSKeyboardDevice : public BSInputDevice
{
public:
};
static_assert(sizeof(BSKeyboardDevice) == 0x70, "BSKeyboardDevice size");

class BSDirectInputManager
{
public:
    void ReleaseDevice(void* a_device);
};
extern BSDirectInputManager* g_directInputManager;

class BSWin32KeyboardDevice : public BSKeyboardDevice
{
public:
    virtual void Unk_09();  // compared: 0xe12c20
    virtual void Unk_0A();  // compared: 0xe12c30
    virtual void Reset();  // compared: 0xe12c00
    virtual void Release();  // compared: 0xe12bd0

    void* device;                  // 70
    std::uint64_t unk78;  // 78
    std::uint64_t unk80;  // 80
    std::uint64_t unk88;  // 88
    std::uint64_t unk90;  // 90
    std::uint64_t unk98;  // 98
    std::uint64_t unkA0;  // A0
    std::uint64_t unkA8;  // A8
    std::uint64_t unkB0;  // B0
    std::uint64_t unkB8;  // B8
    std::uint64_t unkC0;  // C0
    std::uint64_t unkC8;  // C8
    std::uint64_t unkD0;  // D0
    std::uint64_t unkD8;  // D8
    std::uint64_t unkE0;  // E0
    std::uint64_t unkE8;  // E8
    std::uint64_t unkF0;  // F0
    std::uint64_t unkF8;  // F8
    std::uint64_t unk100;  // 100
    std::uint64_t unk108;  // 108
    std::uint64_t unk110;  // 110
    std::uint64_t unk118;  // 118
    std::uint64_t unk120;  // 120
    std::uint64_t unk128;  // 128
    std::uint64_t unk130;  // 130
    std::uint64_t unk138;  // 138
    std::uint64_t unk140;  // 140
    std::uint64_t unk148;  // 148
    std::uint64_t unk150;  // 150
    std::uint64_t unk158;  // 158
    std::uint64_t unk160;  // 160
    std::uint8_t keyState[0x200];  // 168
    std::uint64_t unk368;  // 368
};
static_assert(sizeof(BSWin32KeyboardDevice) == 0x370, "BSWin32KeyboardDevice size");
