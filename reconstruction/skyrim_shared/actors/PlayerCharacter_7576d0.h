// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function reads
// Function7576d0, Node: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Node
{
    void* item;
    Node* next;
};

class PlayerCharacter
{
public:
    bool Function7576d0(void* item);

    char unk000[0x4B0];
    Node unk4B0;
};
