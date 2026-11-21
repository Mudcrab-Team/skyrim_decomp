// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout from observed offsets and public declarations.
// BSPortalGraphEntry, BSPortalGraph, ClearVisibility, AddVisibilityToMap, SetPortalGraph, portalGraph: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSReadWriteLock, LockForWrite, UnlockForWrite: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PortalVisibilityTable, PortalVisibilityBucket, PortalRoomReference, Dispose, ClearRootRoom, and unknown fields: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSCompoundFrustum;
class BSPortalGraph;

class BSReadWriteLock
{
public:
    void LockForWrite();
    void UnlockForWrite();
};

class PortalRoomReference
{
public:
    virtual ~PortalRoomReference();
    virtual void Dispose();
    long refCount;
};

struct PortalVisibilityBucket
{
    void* space;
    BSCompoundFrustum* frustum;
    PortalVisibilityBucket* next;
};

struct PortalVisibilityTable
{
    void Insert(void* const& space, BSCompoundFrustum* const& frustum, bool* result);

    std::uint32_t unknown00;
    std::uint32_t capacity;
    std::uint32_t freeCount;
    std::uint32_t nextFree;
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    PortalVisibilityBucket* buckets;
};

class BSPortalGraphEntry
{
public:
    void ClearVisibility();
    void SetPortalGraph(BSPortalGraph* graph);
    void AddVisibilityToMap(void* space, BSCompoundFrustum* frustum);

private:
    void ClearRootRoom();

    std::uint8_t unknown00[0x10];
    BSPortalGraph* portalGraph;
    std::uint8_t unknown18[0x18];
    PortalRoomReference* rootRoom;
    std::uint8_t unknown38[0x8];
    PortalVisibilityTable visibilityTable;
};
