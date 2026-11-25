// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSMultiBoundNode, FindAncestorOfType, NiAVObjectStandIn, NiRTTIStandIn, parent, kRTTI, GetRTTI: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiRTTIStandIn;

// Minimal stand-in for a scene graph object: vtable slot 2 returns the runtime type, parent at 0x30.
class NiAVObjectStandIn
{
public:
    virtual ~NiAVObjectStandIn();
    virtual void unk01();
    virtual const NiRTTIStandIn* GetRTTI() const;

    std::uint8_t unk08[0x28];
    NiAVObjectStandIn* parent;
};

extern const NiRTTIStandIn kRTTI;

class BSMultiBoundNode
{
public:
    static NiAVObjectStandIn* FindAncestorOfType(NiAVObjectStandIn* a_object);  // compared: 0xff33c0
};
