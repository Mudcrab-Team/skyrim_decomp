// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorMagicCaster, Actor, Actor::magicCasters, Actor::InterruptCast_140631C80: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorMagicCaster::InterruptCast: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::unk00: GUESS(low); unresolved bytes before magicCasters
#pragma once

#include <cstddef>
#include <cstdint>

class ActorMagicCaster
{
public:
    void InterruptCast(bool a_refund);
};

class Actor
{
public:
    void InterruptCast_140631C80(bool a_refund);

    std::uint8_t      unk00[0x1a8];
    ActorMagicCaster* magicCasters[4];  // 0x1a8
};
static_assert(offsetof(Actor, magicCasters) == 0x1a8, "Actor::magicCasters offset");
