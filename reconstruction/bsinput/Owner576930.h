// Source exposure: mixed (community headers and pinned-image analysis).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0xe12490 (bsinput/BSPCGamepadDeviceHandler): source copied, names replaced by placeholders.
// Owner576930: GUESS(low) STANDIN
// currentPCGamePadDelegate, Process, IsEnabled, Shutdown, GetButtonNameFromID, GetKeyCodeFromID, ClearInputState, Functione11f70: GUESS(low) STANDIN
#pragma once
#include "BSPCGamepadDeviceHandler.h"

class Owner576930 : public BSIInputDevice
{
public:
    Owner576930();
    ~Owner576930() override;
    void Process(float a_elapsed) override;
    void Shutdown() override;
    bool GetButtonNameFromID(std::int32_t a_id, char32_t* a_name) override;
    bool GetKeyCodeFromID(std::int32_t a_id, std::uint32_t* a_code) override;
    bool IsEnabled() const override;
    void ClearInputState() override;
    std::uint32_t Functione11f70() const;
    void InitializeDelegate();
    BSPCGamepadDeviceDelegate* currentPCGamePadDelegate;
};
static_assert(sizeof(Owner576930) == 0x10, "gamepad handler size");
