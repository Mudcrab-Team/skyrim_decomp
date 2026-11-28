// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GFxResource, GFxResource::Release: CRASHLOGGER_PDB(59818@2026.10.24)
// GFxResourceLibBase, RemoveResourceOnRelease, refCount, lib: GUESS(low)
#pragma once

#include <intrin.h>
#include <cstdint>
#include <cstddef>

class GFxResource;

class GFxResourceLibBase
{
public:
    virtual ~GFxResourceLibBase();  // 00
    virtual void RemoveResourceOnRelease(GFxResource* a_resource);  // 01 (0x08)
};

class GFxResource
{
public:
    virtual ~GFxResource();  // 00
    void Release();  // compared: 0xd07fb0

    long refCount;  // 08
    GFxResourceLibBase* lib;  // 10
};
static_assert(sizeof(GFxResource) == 0x18, "GFxResource size");
