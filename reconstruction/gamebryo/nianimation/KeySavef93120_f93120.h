// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiLinPosKey, SaveToStream: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names and storage: GUESS(low); element stride observed on the target
#pragma once
#include <cstdint>
struct KeyStreamf93120;
struct KeySavef93120
{
    static void SaveToStream(KeyStreamf93120& stream, KeySavef93120* keys, std::uint32_t count);
    static void SaveBinary(KeyStreamf93120& stream, KeySavef93120* key);
    std::uint32_t unknown00[4];
};
