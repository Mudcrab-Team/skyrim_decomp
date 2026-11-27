// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GRefCountImpl, GRefCountImpl::AddRef, GRefCountImpl::Release, GRefCountImpl::~GRefCountImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount: GUESS(low); the counter that the atomic increment and release update.
// 0xcf31e0 GRefCountImpl::AddRef
// 0xcf3250 GRefCountImpl::Release
#pragma once

#include <intrin.h>
#include <cstdint>
#include <cstddef>

class GRefCountImpl
{
public:
    virtual ~GRefCountImpl();  // 00
    int AddRef();  // 01
    void Release();  // 02

    std::int32_t refCount;  // 08
    std::uint8_t _pad0C[4];  // 0C
};
static_assert(sizeof(GRefCountImpl) == 0x10, "GRefCountImpl size");
