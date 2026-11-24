// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiLinColorKey, SaveToStream: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names and storage: GUESS(low); element stride observed on the target
#pragma once
#include <cstdint>
struct KeyStreamf916b0;
struct KeySavef916b0
{
    static void SaveToStream(KeyStreamf916b0& stream, KeySavef916b0* keys, std::uint32_t count);
    static void SaveBinary(KeyStreamf916b0& stream, KeySavef916b0* key);
    std::uint32_t unknown00[5];
};
