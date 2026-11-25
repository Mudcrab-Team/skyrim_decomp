// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd077d0 GFxResource::AddRef
// Adapted bodies: none
#include "GFxResource.h"

int GFxResource::AddRef()
{
    // The reference count is shared across threads, so it is updated atomically.
    return _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), 1);
}
