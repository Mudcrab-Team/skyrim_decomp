// Source exposure: mixed (pinned image listing; community source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Array304450::~Array304450, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraUsedMarkers304450: CRASHLOGGER_PDB(59818@2026.10.24)
// AllocBase304450, ArrayBase304450, Array304450, Obj304450Base: GUESS(low)
#pragma once

#include <cstdint>

struct AllocBase304450
{
    ~AllocBase304450();
    void Deallocate();

    void* m_data;         // 0x00
    std::uint64_t unk08;  // 0x08
};

struct ArrayBase304450
{
    ~ArrayBase304450();

    std::uint32_t m_size;  // 0x00
};

struct Array304450 : public AllocBase304450, public ArrayBase304450
{
    ~Array304450()
    {
        if (m_data)
        {
            Deallocate();
            m_size = 0;
        }
    }
};
static_assert(sizeof(Array304450) == 0x18, "Array304450 size");

class Obj304450Base
{
public:
    virtual ~Obj304450Base() {}

    std::uint64_t unk08;  // 0x08
};
static_assert(sizeof(Obj304450Base) == 0x10, "Obj304450Base size");

class ExtraUsedMarkers304450 : public Obj304450Base
{
public:
    ExtraUsedMarkers304450();
    ~ExtraUsedMarkers304450() override = default;

    Array304450 m_markers;  // 0x10
};
static_assert(sizeof(ExtraUsedMarkers304450) == 0x28, "ExtraUsedMarkers304450 size");
