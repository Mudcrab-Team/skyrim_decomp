// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::UpdateFlag6ca4c0, StateObject, flags218, GetStateObject675310, GetValue679d00, TestBit: GUESS(low)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

struct StateObject
{
    char unk00[0x218];
    unsigned int flags218;
};

inline bool TestBit(unsigned int flags, unsigned int bit)
{
    return ((flags >> bit) & 1) != 0;
}

class Actor
{
public:
    void UpdateFlag6ca4c0();
    StateObject* GetStateObject675310();
    float GetValue679d00();
};
