// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSDynamicTriShape, BSDynamicTriShape::Functioneeb4f0, BSDynamicTriShape::object, RefCounted, RefCounted::DeleteThis, RefCounted::refCount: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

// Stand-in for a reference-counted object: count at 0x08, delete-self at vtable slot 1.
class RefCounted
{
public:
    virtual ~RefCounted();
    virtual void DeleteThis();

    volatile long refCount;  // 0x08
};

// The class keeps the placeholder name of the unit.
class BSDynamicTriShape
{
public:
    void Functioneeb4f0();

    std::uint8_t pad00[0x18];  // 0x00
    RefCounted* object;  // 0x18
};
