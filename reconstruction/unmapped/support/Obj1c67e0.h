// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj1c67e0::~Obj1c67e0, treated as adapted: shaped like BSTSmartPointerIntrusiveRefCount::Release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTSmartPointer.h:13, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget1c67e0, Obj1c67e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct RefTarget1c67e0
{
    virtual ~RefTarget1c67e0();

    std::uint8_t unk08[0x28];  // 08
    long refCount30;           // 30
};

struct Obj1c67e0
{
    ~Obj1c67e0();  // compared: 0x1c67e0

    RefTarget1c67e0* ptr;  // 00
};
