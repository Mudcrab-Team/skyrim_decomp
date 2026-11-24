// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the method this unit compares
// Function75ed30: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class PlayerCharacter
{
public:
    // The entry receives a pointer into the middle of the object (a secondary base); the
    // three floats read lie a fixed distance before it.
    void Function75ed30(float* out);
};
