// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBezPosKey, DeleteArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// AnimationKeyf961d0 time field: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names and remaining storage: GUESS(low); element size observed on the target
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
struct AnimationKeyf961d0 { float time; };
struct ArrayKeyf961d0 : AnimationKeyf961d0
{
    ~ArrayKeyf961d0();
    static void DeleteArray(AnimationKeyf961d0* keys);
    std::uint32_t unknown04[15];
};
