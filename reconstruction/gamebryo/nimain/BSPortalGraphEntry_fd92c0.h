// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject, BSTArrayHeapAllocator, BSTArrayBase, BSCompoundFrustum, BSPortalGraph, BSMultiBoundRoom, portalGraph, multiBoundRoomAccumList, multiBoundRoomRoot, visibilityMap, compoundFrustum, visibleUnboundSpace, enableAccumulation, unk134, cellId: CRASHLOGGER_PDB(59818@2026.10.24)
// DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// detail::BSTScatterTableSentinel: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// RoomArray, RoomReference, VisibilityEntry, VisibilityMap, ms_totalObjects: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <intrin.h>

class NiRefObject
{
public:
    NiRefObject() : refCount(0)
    {
        // All live reference-counted objects contribute to the shared counter.
        _InterlockedIncrement(&ms_totalObjects);
    }

    virtual ~NiRefObject();
    virtual void DeleteThis();
private:
    static long ms_totalObjects;
    unsigned int refCount;
};

struct BSTArrayHeapAllocator
{
    BSTArrayHeapAllocator();
    ~BSTArrayHeapAllocator();
    void* data;
    unsigned int capacity;
};
struct BSTArrayBase
{
    BSTArrayBase();
    unsigned int size;
};
struct RoomArray : BSTArrayHeapAllocator, BSTArrayBase
{
    ~RoomArray();
};
class BSMultiBoundRoom;
struct RoomReference
{
    BSMultiBoundRoom* room = nullptr;
    ~RoomReference();
};

struct VisibilityEntry;
namespace detail
{
    extern const unsigned char BSTScatterTableSentinel[];
}
struct VisibilityMap
{
    ~VisibilityMap();
    unsigned char unknown00[0xc];
    unsigned int capacity = 0;
    unsigned int freeCount = 0;
    unsigned int nextFree = 0;
    const void* sentinel = detail::BSTScatterTableSentinel;
    unsigned char unknown20[8];
    VisibilityEntry* entries = nullptr;
};

class BSCompoundFrustum
{
public:
    BSCompoundFrustum();
private:
    unsigned char unknown00[0xc8];
};
class BSPortalGraph;

class BSPortalGraphEntry : public NiRefObject
{
public:
    BSPortalGraphEntry();
    ~BSPortalGraphEntry() override;
private:
    BSPortalGraph* portalGraph;
    RoomArray multiBoundRoomAccumList;
    RoomReference multiBoundRoomRoot;
    VisibilityMap visibilityMap;
    BSCompoundFrustum compoundFrustum;
    bool visibleUnboundSpace;
    bool enableAccumulation;
    unsigned int unk134;
    unsigned int cellId;
};
