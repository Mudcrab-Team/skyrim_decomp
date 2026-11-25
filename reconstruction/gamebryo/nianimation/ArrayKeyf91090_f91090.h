// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBezFloatKey, DeleteArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// AnimationKeyf91090 time field: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names and remaining storage: GUESS(low); element size observed on the target
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
struct AnimationKeyf91090 { float time; };
struct ArrayKeyf91090 : AnimationKeyf91090
{
    ~ArrayKeyf91090();
    static void DeleteArray(AnimationKeyf91090* keys);
    std::uint32_t unknown04[3];
};
