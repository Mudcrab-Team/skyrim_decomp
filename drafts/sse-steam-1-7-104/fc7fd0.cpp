// Near miss: 4.0 alignment distance | control-flow
// Exposure detail: community-generated name hints.
// Source exposure: binary-analysis
// Code origin: original; pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// emptyName: GUESS(low); empty fallback text observed at the copy call.
// 0xfc7fd0 QueuedNamedFile::GetName

#include "include/fc7fd0/QueuedNamedFile_fc7fd0.h"

extern const char emptyName[];
extern "C" __declspec(dllimport) int strncpy_s(char*, std::size_t, const char*, std::size_t);

bool QueuedNamedFile::GetName(char* destination, std::uint32_t length) const
{
    const char* name = fileName;
    const char* selected = name ? name : emptyName;
    bool hasName = name != nullptr;
    strncpy_s(destination, static_cast<std::size_t>(length) + 1,
              selected, length);
    return hasName;
}
