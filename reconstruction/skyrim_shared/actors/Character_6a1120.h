// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the state word the body reads
// SIT_SLEEP_STATE, kNormal, kIsSitting, kIsSleeping, ActorState1, ActorState1::sitSleepState, Character::actorState1, Character::GetSitSleepState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared on ActorState there
// Character::Function6a1120: GUESS(low); true while the sit or sleep state is in a transition
// CompareState: GUESS(low); a difference-style state comparison
// Character::unknown00, ActorState1::unknown00, ActorState1::unknown18: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

enum class SIT_SLEEP_STATE : std::uint32_t
{
    kNormal = 0,
    kIsSitting = 3,
    kIsSleeping = 7
};

struct ActorState1
{
    std::uint32_t unknown00 : 14;       // 0:00
    SIT_SLEEP_STATE sitSleepState : 4;  // 0:14
    std::uint32_t unknown18 : 14;       // 0:18
};

// The image masks the state word again for each test, which this compiler only keeps when the
// state is compared as a signed difference; a direct enum compare shares one masked value.
inline std::int32_t CompareState(SIT_SLEEP_STATE a_state, SIT_SLEEP_STATE a_other)
{
    return static_cast<std::int32_t>(a_state) - static_cast<std::int32_t>(a_other);
}

class Character
{
public:
    SIT_SLEEP_STATE GetSitSleepState() const { return actorState1.sitSleepState; }
    bool Function6a1120() const;  // compared: 0x6a1120

    std::uint8_t unknown00[0xC8];  // 00
    ActorState1 actorState1;       // C8
};
