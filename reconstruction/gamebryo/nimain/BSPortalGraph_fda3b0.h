// Source exposure: mixed (local pinned-image analysis and declared community hypotheses).
// Code origin: original graph reconstruction with adapted community lock release.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPortalGraph, StageAlwaysRenderChildAdd, alwaysRenderChildren, NiAVObject, refCount: CRASHLOGGER_PDB(59818@2026.10.24)
// PortalArray, pendingAdds, pendingRemoves, PortalMutex, graphLock, ChildReference, Find: GUESS(low) STANDIN
#pragma once

#include "BSCullingProcess_2036e0.h"
#include <intrin.h>
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct PortalMutex {
    unsigned long owner;
    long count;
    void Lock(unsigned int spins);
    void Unlock() {
        // Order ownership reads and publish the transition before the atomic release.
        _mm_lfence();
        if (owner == GetCurrentThreadId()) {
            if (count == 1) {
                owner = 0;
                // Publish the cleared owner before releasing the lock.
                _mm_mfence();
                // Release the final recursive acquisition atomically.
                _InterlockedCompareExchange(&count, 0, 1);
            } else {
                // Other recursive acquisitions still hold the lock.
                _InterlockedDecrement(&count);
            }
        }
    }
};
extern PortalMutex graphLock;
struct PortalArray : ObjectArray {
    unsigned int Find(NiAVObject* object) const {
        unsigned int found = ~0u;
        unsigned int i = 0;
        const unsigned int size = count.size;
        while (i < size && found == ~0u) {
            unsigned int position = i++;
            if (data[position] == object)
                found = position;
        }
        return found;
    }
    void AppendEntry(NiAVObject* object);
    void RemoveRange(unsigned int index, unsigned int entries);
};
struct BSPortalGraph {
    unsigned char unrecovered00[0x58];
    PortalArray alwaysRenderChildren;
    unsigned char unrecovered70[8];
    PortalArray pendingAdds;
    PortalArray pendingRemoves;
    void StageAlwaysRenderChildAdd(NiAVObject* child);
};
