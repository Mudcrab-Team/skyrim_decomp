// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x19cd20 Obj19cd20::GetOrCreateThreadValue
// Adapted bodies: none.
#include "Obj19cd20.h"

#include <intrin.h>

// Retrieves this thread's cached slot value from TLS or allocates and registers a new slot.
void* Obj19cd20::GetOrCreateThreadValue()
{
    TlsTable19cd20* tbl = table;
    void* val = TlsGetValue(tbl->tlsIndex);
    if (val) {
        return val;
    }
    void* result = 0;
    // atomic slot index claim across threads
    std::uint32_t idx = static_cast<std::uint32_t>(_InterlockedExchangeAdd(&tbl->nextSlot, 1));
    if (idx < tbl->maxSlots) {
        result = CreateSlot(idx);
        tbl->entries[idx].value = result;
        tbl->entries[idx].threadId = GetCurrentThreadId();
        TlsSetValue(tbl->tlsIndex, result);
    }
    return result;
}
