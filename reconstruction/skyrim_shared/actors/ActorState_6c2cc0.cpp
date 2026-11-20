// Source exposure: mixed (pinned image and the cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original movement and weapon-state operations from the pinned image.
// 0x6c2cc0 ActorState::Unk_14
// 0x6e13c0 ActorState::Unk_15
// 0x6e1490 ActorState::Function6e1490
// 0x6e14b0 ActorState::Function6e14b0
// 0x6e14d0 ActorState::Function6e14d0
// 0x6e14f0 ActorState::Function6e14f0
// 0x6e1530 ActorState::Function6e1530
#include "ActorState_6c2cc0.h"

bool ActorState::Unk_14(std::uint32_t state)
{
    stateWord &= ~(0xFu << 14);
    stateWord |= (state & 0xFu) << 14;
    return true;
}

bool ActorState::Unk_15(bool drawn)
{
    const auto previous = (weaponStateWord >> 5) & 7u;
    if (previous != (drawn ? 4u : 1u)) {
        weaponStateWord = (weaponStateWord & ~(7u << 5)) | (drawn ? 3u << 5 : 0u);
    }
    return true;
}

bool ActorState::Function6e1490(std::uint16_t flags)
{
    stateWord &= ~0x3FFFu;
    stateWord |= flags & 0x3FFFu;
    return true;
}

bool ActorState::Function6e14b0(std::uint16_t flags)
{
    stateWord |= flags & 0x3FFFu;
    return true;
}

bool ActorState::Function6e14d0(std::uint16_t flags)
{
    stateWord &= ~static_cast<std::uint32_t>(flags) | ~0x3FFFu;
    return true;
}

std::uint16_t ActorState::Function6e14f0() const
{
    return static_cast<std::uint16_t>(stateWord) & static_cast<std::uint16_t>(0x3FFF);
}

bool ActorState::Function6e1530(std::uint16_t flags) const
{
    return (stateWord & flags & 0x3FFFu) == flags;
}
