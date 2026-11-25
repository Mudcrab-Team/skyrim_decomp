// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor: GUESS(low); the class is the placeholder owner
// SetProcessValue6925f0, ProcessValues, ActorProcess, process, values, flags: GUESS(low)
#pragma once

struct ProcessValues
{
    char unk00[0x18];
    float unk18;
    float unk1C;
    char unk20[0xC];
    unsigned int flags;
};

struct ActorProcess
{
    char unk00[0x50];
    ProcessValues* values;
};

class Actor
{
public:
    void SetProcessValue6925f0(float newValue);

    char unk00[0xF8];
    ActorProcess* process;
};
