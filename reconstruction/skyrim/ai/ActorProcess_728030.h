// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, ActorProcess::RefreshActorExtra, MiddleHighData, nextUpdateTime, Actor: GUESS(low) STANDIN
// Actor::UpdateExtra: GUESS(medium); name of the matched unit at 0x6ac9c0
// GetTickCount: OBSERVED; the Windows API function the image imports
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) std::uint32_t GetTickCount();

struct Actor
{
    void UpdateExtra(bool a_value);
};

struct MiddleHighData
{
    std::uint8_t pad00[0x2F0];
    std::uint64_t nextUpdateTime;  // 2F0
};

class ActorProcess
{
public:
    void RefreshActorExtra(Actor* a_actor, bool a_value);  // compared: 0x728030

    void* unk00;
    MiddleHighData* middleHigh;  // 008
};
