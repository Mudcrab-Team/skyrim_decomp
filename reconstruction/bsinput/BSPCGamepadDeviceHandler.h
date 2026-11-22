// Source exposure: mixed (community headers and pinned-image analysis).
// 0xe11fb0 compared function
// 0xe11f90 compared function
// 0xe11f70 compared function
// 0xe11f50 compared function
// 0xe11f30 compared function
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCGamepadDeviceHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
// IsEnabled: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSIInputDevice { public: virtual ~BSIInputDevice() {} virtual void Initialize(); virtual void Process(float); virtual bool IsEnabled() const; };
class BSPCGamepadDeviceDelegate : public BSIInputDevice {};
// IsEnabled: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functione11f30, Functione11f50, Functione11f70, Functione11f90, Functione11fb0: GUESS(low)
class BSPCGamepadDeviceHandler : public BSIInputDevice { public: BSPCGamepadDeviceHandler(); ~BSPCGamepadDeviceHandler() override; void Process(float) override; bool IsEnabled() const override; void InitializeDelegate(); void Functione11f30(); bool Functione11f50() const; std::uint32_t Functione11f70() const; bool Functione11f90() const; void Functione11fb0(); BSPCGamepadDeviceDelegate* currentPCGamePadDelegate; };
static_assert(sizeof(BSPCGamepadDeviceHandler)==0x10,"gamepad handler size");
extern bool ProcessGamepadEnabledChange;

