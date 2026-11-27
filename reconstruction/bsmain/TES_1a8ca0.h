// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES, TES::unk160, TES::unk168, TES::unk170, TES::unk178: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places the smart pointers 8 bytes earlier
// TES::ClearSlot170: GUESS(low)
// RefCounted, RefCounted::refCount, RefCounted::Release, RefCountedSlot1, RefCountedSlot1::Release: GUESS(low); stand-ins for intrusive refcounted objects
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class RefCounted
{
public:
    virtual ~RefCounted();
    volatile long refCount;  // 0x08

    void Release()
    {
        if (_InterlockedDecrement(&refCount) == 0) {  // intrinsic: atomic refcount decrement
            delete this;
        }
    }
};

class RefCountedSlot1
{
public:
    virtual ~RefCountedSlot1();
    virtual void DeleteThis();
    volatile long refCount;  // 0x08

    void Release()
    {
        if (_InterlockedDecrement(&refCount) == 0) {  // intrinsic: atomic refcount decrement
            DeleteThis();
        }
    }
};

class TES
{
public:
    void ClearSlot170();  // compared: 0x1a8ca0

    std::uint8_t pad00[0x170];
    RefCounted* unk170;  // 0x170
};
