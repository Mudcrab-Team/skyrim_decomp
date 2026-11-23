// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::IsFlagSet6b5cb0, SubObject, gFeatureEnabled, flags164, subObject: GUESS(low)
#pragma once

extern bool gFeatureEnabled;

struct SubObject
{
    char unk00[0x164];
    unsigned char flags164;
};

class Actor
{
public:
    bool IsFlagSet6b5cb0() const;

    char unk00[0x138];
    SubObject* subObject;
};
