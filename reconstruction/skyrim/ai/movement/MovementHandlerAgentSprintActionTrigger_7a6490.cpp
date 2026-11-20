// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x7a6490 MovementHandlerAgentSprintActionTrigger::Function7a6490
// 0x7a6100 MovementHandlerAgentSprintActionTrigger::Function7a6100
#include "MovementHandlerAgentSprintActionTrigger_7a6490.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

std::uint8_t MovementHandlerAgentSprintActionTrigger::Function7a6490() const
{
    return At<std::uint8_t>(this, 0x1c);
}

void MovementHandlerAgentSprintActionTrigger::Function7a6100(std::uint8_t a_value)
{
    At<std::uint8_t>(this, 0x1c) = a_value;
}
