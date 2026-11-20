// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation from the observed map update and room reference operations.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// Adapted bodies: BSWriteLockGuard::BSWriteLockGuard and BSWriteLockGuard::~BSWriteLockGuard from CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp (MIT). SetPortalGraph was reconstructed from the pinned image and shares the graph assignment and room reset with powerof3/CommonLibSSE@654e55f src/RE/B/BSPortalGraphEntry.cpp (GPL-3.0).
// 0xfd96a0 BSPortalGraphEntry::ClearVisibility
// 0xfd9760 BSPortalGraphEntry::SetPortalGraph
// 0xfd98a0 BSPortalGraphEntry::AddVisibilityToMap
#include "BSPortalGraphEntry_fd96a0.h"

#include <intrin.h>

// portalVisibilityLock, ReleaseVisibilityFrustum: GUESS(low)
extern BSReadWriteLock portalVisibilityLock;
void ReleaseVisibilityFrustum(BSCompoundFrustum* frustum);

// BSWriteLockGuard: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSWriteLockGuard
{
public:
    explicit BSWriteLockGuard(BSReadWriteLock& lock) : lock(lock)
    {
        lock.LockForWrite();
    }

    ~BSWriteLockGuard()
    {
        lock.UnlockForWrite();
    }

private:
    BSReadWriteLock& lock;
};

void BSPortalGraphEntry::AddVisibilityToMap(void* space, BSCompoundFrustum* frustum)
{
    BSWriteLockGuard guard(portalVisibilityLock);
    bool inserted;
    visibilityTable.Insert(space, frustum, &inserted);
}

void BSPortalGraphEntry::ClearVisibility()
{
    {
        BSWriteLockGuard guard(portalVisibilityLock);
        PortalVisibilityBucket* bucket = visibilityTable.buckets;
        std::uint32_t capacity;
        if (bucket) {
            capacity = visibilityTable.capacity;
            if (capacity != 0) {
                auto remaining = capacity;
                do {
                    --remaining;
                    if (bucket->next) {
                        ReleaseVisibilityFrustum(bucket->frustum);
                        bucket->next = nullptr;
                    }
                    ++bucket;
                } while (remaining != 0);
                capacity = visibilityTable.capacity;
            }
        } else {
            visibilityTable.capacity = 0;
            capacity = 0;
        }
        visibilityTable.freeCount = capacity;
        visibilityTable.nextFree = capacity;
    }

    ClearRootRoom();
}

inline void BSPortalGraphEntry::ClearRootRoom()
{
    PortalRoomReference* previousRoot = rootRoom;
    if (previousRoot) {
        rootRoom = nullptr;
        // The reference count must drop atomically before disposal.
        if (_InterlockedExchangeAdd(&previousRoot->refCount, -1) == 1) {
            previousRoot->Dispose();
        }
    }
}

void BSPortalGraphEntry::SetPortalGraph(BSPortalGraph* graph)
{
    portalGraph = graph;
    ClearRootRoom();
}
