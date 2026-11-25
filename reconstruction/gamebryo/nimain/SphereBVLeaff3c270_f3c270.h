// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiSphereBV, NiBoundingVolume: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); the used slot and offset are observed on the target
#pragma once
#include <cstdint>

struct BoundingVolumeLeaf;
struct BoundingVolumeTable
{
    void* unknown00[3];
    std::int32_t (*type)(const BoundingVolumeLeaf*);
};
struct BoundingVolumeLeaf { BoundingVolumeTable* table; };
struct SpherePayload
{
    bool operator==(const SpherePayload& other) const;
    std::uint32_t unknown00;
};
struct SphereBVLeaff3c270 : BoundingVolumeLeaf
{
    bool operator==(const BoundingVolumeLeaf& other) const;
    SpherePayload sphere;
};
