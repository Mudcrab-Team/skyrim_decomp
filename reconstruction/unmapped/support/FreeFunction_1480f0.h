// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function1480f0: GUESS(low)
// Triplet1480f0: GUESS(low)
// LoadBuffer1480f0: GUESS(low) STANDIN
// LoadDataEndian: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

struct Triplet1480f0
{
    std::uint32_t first;
    std::uint32_t second;
    std::uint32_t third;
};

// guess: stand-in for the save-game load buffer; the PDB names the callee BGSLoadGameBuffer::LoadDataEndian.
struct LoadBuffer1480f0
{
    void LoadDataEndian(void* data, std::uint32_t size, std::uint32_t stride);
};

void Function1480f0(Triplet1480f0* record, LoadBuffer1480f0* buffer);
