// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiSearchPath, SetFilePath: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in fields and helper: GUESS(low); buffer offset and bound observed on the target
#pragma once
#include <cstdint>

void NormalizeSearchPath(char* path);
struct SearchPathLeafeaefd0
{
    void SetFilePath(const char* file);
    std::uint8_t unknown00[12];
    char path[260];
};
