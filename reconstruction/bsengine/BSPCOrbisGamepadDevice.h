// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCOrbisGamepadDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
class BSIInputDevice { public: virtual ~BSIInputDevice() {} virtual void Initialize(); virtual void Process(float); virtual void Release(); virtual void Mapping0(); virtual void Mapping1(); virtual void Mapping2(); virtual bool IsEnabled() const; virtual void Reset(); };
struct ButtonMapTail { ~ButtonMapTail(); std::uint32_t unknown00,capacity,freeCount,good; void* sentinel; std::uint64_t allocatorState; void* entries; };
struct NameMapTail { ~NameMapTail(); std::uint32_t unknown00,capacity,freeCount,good; void* sentinel; std::uint64_t allocatorState; void* entries; };
struct ButtonMap { std::uint64_t unknown00; ButtonMapTail tail; };
struct NameMap { std::uint64_t unknown00; NameMapTail tail; };
class BSInputDevice : public BSIInputDevice { public: ~BSInputDevice() override { ResetButtonMaps(); } void ResetButtonMaps(); std::uint32_t device; ButtonMap deviceButtons; NameMap buttonNameIDMap; };
static_assert(sizeof(BSInputDevice)==0x70,"input device size");
struct GamepadArray { void** data; std::uint32_t capacity,allocatorState,count,unknown14; };
struct GamepadEventSource { GamepadArray sinks,pendingRegisters,pendingUnregisters; std::uint32_t lockThread,lockCount; bool notifying; };
class BSGamepadDevice : public BSInputDevice, public GamepadEventSource { public: virtual void SetRumble(float,float); virtual void ProcessRawInput(std::int32_t,std::int32_t,float&,float&); std::int32_t userIndex; bool connected,listeningForInput; };
class BSPCGamepadDeviceDelegate : public BSGamepadDevice { public: void* gamepadDeviceHandler; };
struct PadVector3 { float x,y,z; }; struct PadVector4 { float x,y,z,w; };
struct PadTouch { std::uint16_t x,y; std::uint8_t touchID; std::uint8_t reserved5; std::uint16_t reserved6; };
struct TouchPadData { std::uint8_t touchNum; std::uint8_t reserved1; std::uint16_t reserved2; std::uint32_t reserved4; PadTouch touch[2]; };
struct ExtensionData { std::uint32_t unitID; std::uint8_t reserved4,dataLength; std::uint8_t data[10]; };
struct GamepadData { std::uint32_t buttonState; std::uint8_t rawLeftStickX,rawLeftStickY,rawRightStickX,rawRightStickY,rawLeftTrigger,rawRightTrigger; std::uint16_t reservedA; PadVector4 orientation; PadVector3 acceleration,angularVelocity; TouchPadData touchPad; bool connected; std::uint8_t reserved4D; std::uint16_t reserved4E; std::uint64_t timestamp; ExtensionData extension; std::uint8_t connectedCount,reserved69,reserved6A,specialDataLen; std::uint8_t specialData[12]; };
class BSPCOrbisGamepadDevice : public BSPCGamepadDeviceDelegate { public: void SetRumble(float,float) override; void ProcessRawInput(std::int32_t,std::int32_t,float&,float&) override; GamepadData previous; float previousLT,previousRT,previousLX,previousLY,previousRX,previousRY; GamepadData current; float currentLT,currentRT,currentLX,currentLY,currentRX,currentRY; }; static_assert(sizeof(BSPCOrbisGamepadDevice)==0x1F8,"Orbis gamepad size");
struct RumbleValues { std::uint8_t left,right; }; void ApplyRumble(std::int32_t,const RumbleValues*); float MapRawAxis(float,float,float,float,float);

