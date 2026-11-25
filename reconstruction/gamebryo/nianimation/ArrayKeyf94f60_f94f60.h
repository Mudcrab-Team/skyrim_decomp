// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTCBPosKey, DeleteArray: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// AnimationKeyf94f60 time field: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names and remaining storage: GUESS(low); element size observed on the target
#pragma once
#include <cstdint>
void operator delete[](void*, unsigned __int64) noexcept;
struct AnimationKeyf94f60 { float time; };
struct ArrayKeyf94f60 : AnimationKeyf94f60
{
    ~ArrayKeyf94f60();
    static void DeleteArray(AnimationKeyf94f60* keys);
    std::uint32_t unknown04[18];
};
