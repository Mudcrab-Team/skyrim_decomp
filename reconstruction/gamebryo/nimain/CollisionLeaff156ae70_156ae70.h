// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiCollisionObject, IsEqual: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offset observed on the target
#pragma once
#include <cstdint>

struct CollisionBase
{
    bool IsEqual(CollisionBase* other);
    std::uint64_t state[2];
};
struct CollisionLeaff156ae70 : CollisionBase
{
    bool IsEqual(CollisionBase* other);
    void* scene;
};
