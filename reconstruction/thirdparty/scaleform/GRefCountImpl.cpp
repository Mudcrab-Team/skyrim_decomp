// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcf31e0 GRefCountImpl::AddRef
// 0xcf3250 GRefCountImpl::Release
// Adapted bodies: none
#include "GRefCountImpl.h"

int GRefCountImpl::AddRef()
{
    // The reference count is shared across threads, so it is updated atomically.
    return _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), 1);
}

void GRefCountImpl::Release()
{
    // The last owner to release the object destroys it; the count is shared across threads.
    if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), -1) == 1) {
        delete this;
    }
}
