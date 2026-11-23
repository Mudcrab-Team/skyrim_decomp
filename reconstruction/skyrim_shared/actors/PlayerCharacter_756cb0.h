// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function reads
// Function756cb0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low)
// GetSlotHandle, kNullHandle: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern const std::uint32_t kNullHandle;

class PlayerCharacter
{
public:
    std::uint32_t* Function756cb0(std::uint32_t* out);

    const std::uint32_t& GetSlotHandle() const;

    char unk000[0x7F0];
    std::uint32_t unk7F0[(0x8A0 - 0x7F0) / 4];
    std::int32_t unk8A0;
};
