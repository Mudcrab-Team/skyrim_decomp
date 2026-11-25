// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiEulerRotKey, DeleteArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// AnimationKeyf6dfa0 time field: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names and remaining storage: GUESS(low); element size observed on the target
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
struct AnimationKeyf6dfa0 { float time; };
struct ArrayKeyf6dfa0 : AnimationKeyf6dfa0
{
    ~ArrayKeyf6dfa0();
    static void DeleteArray(AnimationKeyf6dfa0* keys);
    std::uint32_t unknown04[21];
};
