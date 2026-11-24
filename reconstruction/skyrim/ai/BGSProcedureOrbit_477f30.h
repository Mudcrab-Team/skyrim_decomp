// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSProcedureOrbit, BGSProcedureOrbit::Run, GrabArgs, GrabState, Character, Character::Function673b40: GUESS(low)
#pragma once

class Character
{
public:
    bool Function673b40();
};

struct GrabState
{
    char unk00[0x18];
    bool done;
};

struct GrabArgs
{
    Character** actor;
    GrabState* state;
};

class BGSProcedureOrbit
{
public:
    void Run(GrabArgs* args);  // compared: 0x477f30
};
