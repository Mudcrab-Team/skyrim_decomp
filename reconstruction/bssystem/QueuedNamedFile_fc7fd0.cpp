// Source exposure: binary-analysis; community-generated name hints.
// Code origin: original; pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0xfc7fd0 QueuedNamedFile::GetName
// Adapted bodies: none.
// emptyName: GUESS(low); empty fallback text observed at the copy call.
#include "QueuedNamedFile_fc7fd0.h"

extern const char emptyName[];
extern "C" __declspec(dllimport) int strncpy_s(char*, std::size_t, const char*, std::size_t);

bool QueuedNamedFile::GetName(char* destination, std::uint32_t length) const
{
    const char* name = fileName;
    bool hasName = false;
    if (name)
        hasName = true;
    else
        name = emptyName;
    strncpy_s(destination, static_cast<std::size_t>(length) + 1, name, length);
    return hasName;
}
