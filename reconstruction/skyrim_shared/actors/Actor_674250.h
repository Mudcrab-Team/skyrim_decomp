// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a view of the ActorState base and the process pointer only
// Actor::QDoubleGravity: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// Actor::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places it at 0xf0, this build reads 0xf8
// AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only its pointer is tested
// ActorState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); base subobject at 0xc0, modelled as a member
// ActorState::Function6e14f0: GUESS(low); callee at RVA 0x6e14f0 returning a 16-bit flag word
#pragma once

#include <cstdint>
#include <cstddef>

class AIProcess;

class ActorState
{
public:
    std::uint16_t Function6e14f0() const;
};

class Actor
{
public:
    bool QDoubleGravity();  // compared: 0x674250

    std::uint8_t pad00[0xC0];
    ActorState actorState;  // 0xc0
    std::uint8_t padC1[0xF8 - 0xC1];
    AIProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, actorState) == 0xC0, "actorState");
static_assert(offsetof(Actor, currentProcess) == 0xF8, "currentProcess");
