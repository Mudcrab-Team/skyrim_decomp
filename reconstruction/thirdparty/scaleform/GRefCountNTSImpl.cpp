// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: the cited community declarations and body, checked against the pinned game build.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xcf3270 GRefCountNTSImpl::Release
// Adapted bodies: GRefCountNTSImpl::Release, CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GRefCountNTSImpl.cpp:10 (MIT).
#include "GRefCountNTSImpl.h"

void GRefCountNTSImpl::Release()
{
    // Not thread-safe: a plain decrement, and the last owner destroys the object.
    --_refCount;
    if (_refCount == 0) {
        delete this;
    }
}
