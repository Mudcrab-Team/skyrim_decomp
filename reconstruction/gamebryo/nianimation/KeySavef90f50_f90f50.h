// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiLinPosKey, SaveToStream: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names and storage: GUESS(low); element stride observed on the target
#pragma once
#include <cstdint>
struct KeyStreamf90f50;
struct KeySavef90f50
{
    static void SaveToStream(KeyStreamf90f50& stream, KeySavef90f50* keys, std::uint32_t count);
    static void SaveBinary(KeyStreamf90f50& stream, KeySavef90f50* key);
    std::uint32_t unknown00[4];
};
