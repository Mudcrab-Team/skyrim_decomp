// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// NiBSPNode, NiBSPNode::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, NiNode::IsEqual, NiObject: GUESS(low)
// modelPlane, NiNode storage: OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>
class NiObject;
class NiNode {
public:
    bool IsEqual(NiObject* other);
    std::uint8_t nodeStorage[0x128];
};
class NiBSPNode : public NiNode {
public:
    bool IsEqual(NiObject* other);
    float modelPlane[4];
};
static_assert(offsetof(NiBSPNode, modelPlane) == 0x128, "model plane offset");
