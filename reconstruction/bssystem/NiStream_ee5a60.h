// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiStream::GetNextSearchPath as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nistream.cpp:359
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::GetNextSearchPath: CRASHLOGGER_PDB(59818@2026.10.24)
// gSearchPathAvailable, NiStream::unk00, NiStream::searchPath: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern bool gSearchPathAvailable;

class NiStream
{
public:
    bool GetNextSearchPath(char* a_dest, std::uint32_t a_destSize);

    std::uint8_t unk00[0x518];
    char searchPath[260];
};
static_assert(offsetof(NiStream, searchPath) == 0x518, "searchPath offset");
