// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPathingNode, BSPathingLocation, location, actionAtNode: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, BSTSmartPointer, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MovementMessage: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// tangent, ptr, refCount, unk00, unk44: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class MovementMessage
{
public:
    virtual ~MovementMessage();

    // volatile: reference count is updated atomically across threads
    volatile long refCount;  // 08
};

template <class T>
class BSTSmartPointer
{
public:
    BSTSmartPointer(const BSTSmartPointer& other)
    {
        ptr = other.ptr;
        if (other.ptr)
        {
            // hot path: atomic reference count increment on smart-pointer copy
            _InterlockedIncrement(&other.ptr->refCount);
        }
    }

    T* ptr;  // 00
};

class BSPathingLocation
{
public:
    BSPathingLocation(const BSPathingLocation& other);

    std::uint8_t unk00[0x30];  // 00
};
static_assert(sizeof(BSPathingLocation) == 0x30, "BSPathingLocation size");

class NiPoint3
{
public:
    NiPoint3(const NiPoint3& other) : x(other.x), y(other.y), z(other.z) {}

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class BSPathingNode
{
public:
    BSPathingNode(const BSPathingNode& other);

    BSPathingLocation                location;      // 00
    BSTSmartPointer<MovementMessage> actionAtNode;  // 30
    NiPoint3                         tangent;       // 38
    std::uint32_t                    unk44;         // 44
};
static_assert(sizeof(BSPathingNode) == 0x48, "BSPathingNode size");
