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
    // Intrusive ownership releases must update the count atomically.
    if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&refCount), -1) == 1 && this != nullptr) {
        using DeletingDtorFn = void(__thiscall*)(void*, unsigned int);
        auto vtable = *reinterpret_cast<void***>(this);
        reinterpret_cast<DeletingDtorFn>(vtable[0])(this, 1);
    }
}
