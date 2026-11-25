// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBezRotKey, SaveToStream: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names and storage: GUESS(low); element stride observed on the target
#pragma once
#include <cstdint>
struct KeyStreamf8f550;
struct KeySavef8f550
{
    static void SaveToStream(KeyStreamf8f550& stream, KeySavef8f550* keys, std::uint32_t count);
    static void SaveBinary(KeyStreamf8f550& stream, KeySavef8f550* key);
    std::uint32_t unknown00[9];
};
