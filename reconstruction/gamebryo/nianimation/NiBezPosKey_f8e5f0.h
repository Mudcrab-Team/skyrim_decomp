// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBezPosKey, NiPosKey, LoadBinary, NiStream: SIBLING(fo4-private@1b765c70, author-permission)
// Field names and base storage: GUESS(low); stand-ins for target offsets
#pragma once
#include <cstdint>

class NiStream;
struct PointValue
{
    void LoadBinary(NiStream& stream);
    float x, y, z;
};
struct NiPosKey
{
    void LoadBinary(NiStream& stream);
    std::uint8_t state[16];
};
struct NiBezPosKey : NiPosKey
{
    void LoadBinary(NiStream& stream);
    PointValue incoming;
    PointValue outgoing;
};
