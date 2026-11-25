// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x69f920 (skyrim_shared/actors/Actor_69f920): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPerk: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorProcess: GUESS(low); the placeholder owner, NG calls the class AIProcess
// Function6a68f0, Owner6a68f0: GUESS(low) STANDIN
// currentProcess, pad08: GUESS(low) STANDIN
#pragma once
#include "Actor_69f920.h"

class Owner6a68f0
{
public:
    virtual ~Owner6a68f0();

    std::uint8_t Function6a68f0(BGSPerk* a_perk);

    std::uint8_t pad08[0xF0];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Owner6a68f0, currentProcess) == 0xf8, "Owner6a68f0::currentProcess offset");
