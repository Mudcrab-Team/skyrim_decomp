// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj31d290::~Obj31d290, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ArrayBase31d290, AllocBase31d290, Obj31d290: GUESS(low)
#pragma once

#include <cstdint>

struct AllocBase31d290
{
    ~AllocBase31d290();
    void Deallocate();

    void* m_data;         // 0x00
    std::uint64_t unk08;  // 0x08
};

struct ArrayBase31d290
{
    ~ArrayBase31d290();

    std::uint32_t m_size;  // 0x00
};

class Obj31d290 : public AllocBase31d290, public ArrayBase31d290
{
public:
    ~Obj31d290();
};
