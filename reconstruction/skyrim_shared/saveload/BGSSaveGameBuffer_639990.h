// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: WriteRaw, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// BGSSaveGameBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// SaveFile639990, SaveManager639990, gSaveManager, WriteToFile, WriteHeader, bytesWritten, writeFn, buffer, size, skipPayload: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct SaveFile639990
{
    using WriteFn = std::uint32_t (*)(SaveFile639990*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    void WriteHeader(const void* a_data, std::uint32_t a_size);

    std::uint8_t unk00[0x08];
    std::uint32_t bytesWritten;
    std::uint32_t unk0C;
    std::uint64_t unk10;
    WriteFn writeFn;
};

struct SaveManager639990
{
    std::uint8_t unk00[0x120];
    bool skipPayload;
};

extern SaveManager639990* gSaveManager;

class BGSSaveGameBuffer
{
public:
    void WriteToFile(SaveFile639990* a_file);

    std::uint8_t unk00[0x08];
    void* buffer;
    std::uint32_t unk10;
    std::uint32_t size;
};

static_assert(offsetof(SaveFile639990, bytesWritten) == 0x08, "bytesWritten offset");
static_assert(offsetof(SaveFile639990, writeFn) == 0x18, "writeFn offset");
static_assert(offsetof(SaveManager639990, skipPayload) == 0x120, "skipPayload offset");
static_assert(offsetof(BGSSaveGameBuffer, buffer) == 0x08, "buffer offset");
static_assert(offsetof(BGSSaveGameBuffer, size) == 0x14, "size offset");
