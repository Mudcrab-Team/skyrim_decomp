// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: local stand-ins (no ancestor has a shared header).
// GFxResource, GFxResource::AddRef, GFxResource::~GFxResource, GFxResource::GetKey, GFxResource::GetResourceTypeCode, GFxResource::GetResourceReport: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GNewOverrideBase, GFxResourceReport: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount: GUESS(low); the counter that the atomic increment updates.
// 0xd077d0 GFxResource::AddRef
#pragma once

#include <intrin.h>
#include <cstdint>
#include <cstddef>

class GFxResourceReport;

class GFxResourceKey
{
public:
    const char* _data;
};

class GNewOverrideBase
{
public:
};

class GFxResource : public GNewOverrideBase
{
public:
    virtual ~GFxResource();  // 00
    virtual GFxResourceKey GetKey();  // 01
    virtual std::uint32_t GetResourceTypeCode() const;  // 02
    virtual GFxResourceReport* GetResourceReport();  // 03
    int AddRef();  // 04

    std::int32_t refCount;  // 08
    std::uint8_t _pad0C[0xC];  // 0C
};
static_assert(sizeof(GFxResource) == 0x18, "GFxResource size");
