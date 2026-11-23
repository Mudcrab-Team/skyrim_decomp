// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::HasSubObject6d4620, SubObject, pad, embedded, tag: GUESS(low)
// Function164140: GUESS(low)
#pragma once

struct SubObject
{
    char tag;
};

void* Function164140(SubObject* sub);

class Actor
{
public:
    bool HasSubObject6d4620();

    char pad[0x70];
    SubObject embedded;
};
