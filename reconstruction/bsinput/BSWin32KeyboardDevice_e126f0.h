// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSWin32KeyboardDevice, BSWin32KeyboardDevice::Initialize, dInputDevice, capsLockOn, BSDirectInputManager, CreateDeviceWithGUID: CRASHLOGGER_PDB(59818@2026.10.24)
// GetForegroundWindow, GetKeyState: OBSERVED
// IDirectInputDevice8A, DIPROPDWORD, GUID, gDirectInputManager, gGuidSysKeyboard, gKeyboardDataFormat, keyStates, unknown00, unknown78: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct GUID
{
    std::uint32_t data1;
    std::uint16_t data2;
    std::uint16_t data3;
    std::uint8_t data4[8];
};

struct DIPROPDWORD
{
    std::uint32_t size;
    std::uint32_t headerSize;
    std::uint32_t obj;
    std::uint32_t how;
    std::uint32_t data;
};

struct DIDATAFORMAT;

extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow();
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int a_virtKey);

class IDirectInputDevice8A
{
public:
    virtual ~IDirectInputDevice8A();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual long SetProperty(std::uintptr_t a_prop, const DIPROPDWORD* a_header);  // slot 06 (+0x30)
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual long SetDataFormat(const DIDATAFORMAT* a_format);                      // slot 0B (+0x58)
    virtual void Slot0C();
    virtual long SetCooperativeLevel(void* a_hwnd, std::uint32_t a_flags);         // slot 0D (+0x68)
};

class BSDirectInputManager
{
public:
    IDirectInputDevice8A* CreateDeviceWithGUID(const GUID* a_guid);
};

extern BSDirectInputManager* gDirectInputManager;
extern const GUID gGuidSysKeyboard;
extern const DIDATAFORMAT gKeyboardDataFormat;

class BSWin32KeyboardDevice
{
public:
    void Initialize();  // compared: 0xe126f0

    std::uint8_t unknown00[0x70];
    IDirectInputDevice8A* dInputDevice;  // 70
    std::uint8_t unknown78[0xF0];        // 78
    std::uint8_t keyStates[2][0x100];       // 168
    bool capsLockOn;                     // 368
};
static_assert(offsetof(BSWin32KeyboardDevice, dInputDevice) == 0x70, "dInputDevice offset");
static_assert(offsetof(BSWin32KeyboardDevice, keyStates) == 0x168, "keyStates offset");
static_assert(offsetof(BSWin32KeyboardDevice, capsLockOn) == 0x368, "capsLockOn offset");
