// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::RTTIError: CRASHLOGGER_PDB(59818@2026.10.24)
// gRttiErrorSuffix, NiStream::unk00, NiStream::lastError, NiStream::lastErrorMessage: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const char gRttiErrorSuffix[];

class NiStream
{
public:
    void RTTIError(const char* a_rttiName);

    std::uint8_t unk00[0x410];
    std::uint32_t lastError;
    char lastErrorMessage[260];
};
static_assert(offsetof(NiStream, lastError) == 0x410, "lastError offset");
static_assert(offsetof(NiStream, lastErrorMessage) == 0x414, "lastErrorMessage offset");
