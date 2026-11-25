// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MovementTweenerAgentNodeFollower, Function7ab5f0, Target, unk20, unk28, Register, Unregister, g_followerKey: GUESS(low)
#pragma once

struct FollowerKey { int unk; };
extern const FollowerKey g_followerKey;  // data at 0x324fe98

class Target
{
public:
    virtual void unk00();
    virtual void Register(const FollowerKey* a_key, void* a_slot);
    virtual void unk02();
    virtual void unk03();
    virtual void Unregister(const FollowerKey* a_key);
};

class MovementTweenerAgentNodeFollower
{
public:
    void Function7ab5f0();  // compared: 0x7ab5f0

    char unk00[0x20];
    char unk20[8];
    Target* unk28;
};
