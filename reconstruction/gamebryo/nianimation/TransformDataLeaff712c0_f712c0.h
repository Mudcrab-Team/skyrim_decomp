// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTransformData, CleanRotAnim: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types, storage and helper names: GUESS(low); offsets observed on the target
#pragma once
#include <cstdint>

struct RotationKey;
struct TransformDataLeaff712c0
{
    void CleanRotAnim(RotationKey* keys, std::uint32_t count, std::int32_t type);
    std::uint8_t unknown00[0x18];
    std::int32_t rotationType;
};
using RotationDelete = void (*)(RotationKey*);
extern RotationDelete gRotationDeleteTable[];
void CleanEulerKeys(RotationKey* keys);
