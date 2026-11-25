// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysVolumeEmitter, IsEqual: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offset observed on the target
#pragma once
#include <cstdint>

struct EmitterObject { std::uint8_t state[0x70]; };
struct EmitterBase : EmitterObject { bool IsEqual(EmitterObject* other); };
struct VolumeEmitterLeaffc03d0 : EmitterBase
{
    bool IsEqual(EmitterObject* other);
    void* volume;
};
