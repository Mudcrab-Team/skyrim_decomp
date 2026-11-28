// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BeamProjectile, BeamProjectile::Func1_v5: CRASHLOGGER_PDB(59818@2026.10.24); listed name may belong to BSQueuedResourceCollectionBase
// strncpy_s: OBSERVED
// gDescriptionLabel: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl strncpy_s(char* a_dest, std::size_t a_destSize, const char* a_src, std::size_t a_count);
extern const char gDescriptionLabel[];

class BeamProjectile
{
public:
    bool Func1_v5(char* a_buffer, std::uint32_t a_maxCount);  // compared: 0xfc8460
};
