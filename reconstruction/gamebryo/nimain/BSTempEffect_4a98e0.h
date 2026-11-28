// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiRefObject, NiRefObject::_refCount, ::DeleteThis: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::totalObjectCount: GUESS(low); CommonLib reaches the counter through GetTotalObjectCount
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); destructor and the 0x10 byte header only
// BSTempEffect, BSTempEffect::lifetime, ::cell, ::age, ::initialized, ::effectID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include <cstdint>
#include <intrin.h>

class TESObjectCELL;

class NiRefObject
{
public:
    // atomic decrement: the live object count is shared between threads
    virtual ~NiRefObject() { _InterlockedDecrement(&totalObjectCount); }
    virtual void DeleteThis();

    // volatile: updated with interlocked operations from every thread that creates or destroys a reference object
    static volatile long totalObjectCount;

    // volatile: reference count changed with interlocked operations
    volatile std::uint32_t _refCount;  // 08
    std::uint32_t          unk0C;      // 0C
};

class NiObject : public NiRefObject
{
public:
    ~NiObject() override {}
};

class BSTempEffect : public NiObject
{
public:
    ~BSTempEffect() override;

    float          lifetime;     // 10
    std::uint32_t  unk14;        // 14
    TESObjectCELL* cell;         // 18
    float          age;          // 20
    bool           initialized;  // 24
    std::uint8_t   unk25;        // 25
    std::uint16_t  unk26;        // 26
    std::uint32_t  effectID;     // 28
    std::uint32_t  unk2C;        // 2C
};
static_assert(offsetof(BSTempEffect, initialized) == 0x24, "layout differs from CommonLibSSE-NG");
static_assert(sizeof(BSTempEffect) == 0x30, "layout differs from CommonLibSSE-NG");
