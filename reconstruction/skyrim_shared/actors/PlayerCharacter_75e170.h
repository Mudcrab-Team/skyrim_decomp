// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to what this function reads
// Function75e170, gPlayerLocation, gPlayerSingleton: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Vec3
{
    float x;
    float y;
    float z;
};

class PlayerCharacter;
extern PlayerCharacter* gPlayerSingleton;
extern Vec3 gPlayerLocation;

class PlayerCharacter
{
public:
    static void Function75e170();

    char unk000[0x54];
    Vec3 unk54;
};
