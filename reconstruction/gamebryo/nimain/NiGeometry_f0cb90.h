// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiGeometry, NiGeometry::SetSmartPointerMember, NiRefObject stand-in, spData: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// Minimal stand-in: reference counted object with a virtual deleting slot 1.
class NiRefObjectStandIn
{
public:
    virtual ~NiRefObjectStandIn();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

class NiGeometry
{
public:
    void SetSmartPointerMember(NiRefObjectStandIn* a_obj);  // compared: 0xf0cb90

    std::uint8_t unk00[0x110];
    NiRefObjectStandIn* spData;
};
