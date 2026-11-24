// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::IsFlagged6cb980, ActorProcess, GetSlot700c60, Holder, SlotOwner, gHolder, process, flags28, statusFlags: GUESS(low)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

inline bool TestBit(unsigned int flags, unsigned int bit)
{
    return ((flags >> bit) & 1) != 0;
}

struct Holder
{
    char unk00[0x28];
    unsigned int flags28;
};

struct ActorProcess
{
    Holder** GetSlot700c60();
};

extern Holder* gHolder;

class Actor
{
public:
    bool IsFlagged6cb980() const;

    char unk00[0xC8];
    unsigned int statusFlags;
    char unkCC[0x2C];
    ActorProcess* process;
};
