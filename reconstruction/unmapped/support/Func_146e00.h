// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Base146e00: GUESS(low)
// Func_146e00: GUESS(low)
#pragma once

struct Base146e00
{
    virtual ~Base146e00();
};

struct Func_146e00 : Base146e00
{
    ~Func_146e00() override;
    void Cleanup();
};
