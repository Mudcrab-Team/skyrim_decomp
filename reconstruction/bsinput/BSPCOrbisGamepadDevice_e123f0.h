// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPCOrbisGamepadDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSPCGamepadDeviceDelegate: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BSPCGamepadDeviceDelegate
{
public:
    virtual ~BSPCGamepadDeviceDelegate();

private:
    std::uint8_t padding08[0xD0];
};

class BSPCOrbisGamepadDevice : public BSPCGamepadDeviceDelegate
{
public:
    BSPCOrbisGamepadDevice();
    ~BSPCOrbisGamepadDevice() override = default;

private:
    std::uint8_t paddingD8[0x120];
};
static_assert(sizeof(BSPCOrbisGamepadDevice) == 0x1F8, "observed allocation size");
