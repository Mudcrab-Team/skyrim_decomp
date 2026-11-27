// Source exposure: mixed (pinned image listing, labelled declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation. Stamped as a twin of matched 0x4f76b0 (skyrim_shared/pathfinding/PathingRequestFlyOrbit): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x7c1f00 Owner7c1f00::Function7c1f00
// orbitPoint: GUESS(low) STANDIN
#include "Owner7c1f00.h"

// Write the orbit point into the caller's result.
NiPoint3& Owner7c1f00::Function7c1f00(NiPoint3& a_out) const
{
    a_out.x = orbitPoint.x;
    a_out.y = orbitPoint.y;
    a_out.z = orbitPoint.z;
    return a_out;
}
