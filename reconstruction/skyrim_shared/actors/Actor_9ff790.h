// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::HasPerk9ff790, VM, LogError, Perk, Function69f920, perkError: GUESS(low)
// HasPerk9ff790: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
struct VM {
    virtual void unk00();
    virtual void unk01();
    virtual bool LogError(const char* message, unsigned int stackId, int severity);
};
struct Perk;
extern const char perkError[];
class Actor {
public:
    static bool HasPerk9ff790(VM* vm, unsigned int stackId, Actor* actor, Perk* perk);
    unsigned char Function69f920(Perk& perk);
};
