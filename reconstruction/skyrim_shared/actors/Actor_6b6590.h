// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::IsFlagClear6b6590, ActorProcess, process, flag137: GUESS(low)
#pragma once

struct ActorProcess
{
    char unk00[0x137];
    unsigned char flag137;
};

class Actor
{
public:
    bool IsFlagClear6b6590() const;

    char unk00[0xF8];
    ActorProcess* process;
};
