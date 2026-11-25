// Source exposure: binary-analysis; community-generated name hints.
// Code origin: original; pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// QueuedNamedFile, QueuedNamedFile::GetName: CRASHLOGGER_PDB(59818@2026.10.24)
// opaque00, fileName: GUESS(low); inferred private filename field and unknown prefix.
#pragma once
#include <cstddef>
#include <cstdint>

class QueuedNamedFile
{
public:
    bool GetName(char* destination, std::uint32_t length) const;
    std::uint8_t opaque00[0x38];
    const char* fileName;
};
static_assert(offsetof(QueuedNamedFile, fileName) == 0x38, "observed filename offset");
