// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiAnimationKey layout: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBoolKey, Equal: SIBLING(fo4-private@1b765c70, author-permission)
// value: GUESS(low); stored width and offset observed on the target
#pragma once
#include <cstdint>

struct NiAnimationKey
{
    float time;
    static bool Equal(const NiAnimationKey& first, const NiAnimationKey& second);
};
struct NiBoolKey : NiAnimationKey
{
    std::uint8_t value;
    static bool Equal(const NiAnimationKey& first, const NiAnimationKey& second);
};
