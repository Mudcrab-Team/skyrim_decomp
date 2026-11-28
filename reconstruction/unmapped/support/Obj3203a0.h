// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Array3203a0::~Array3203a0 and RemoveAt, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::erase (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:525, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AllocBase3203a0, ArrayBase3203a0, Array3203a0, Obj3203a0, Obj3203a0::FlushPending: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct AllocBase3203a0
{
    ~AllocBase3203a0();
    void Deallocate();

    void** m_data;        // 0x00
    std::uint64_t unk08;  // 0x08
};

struct ArrayBase3203a0
{
    ~ArrayBase3203a0();
    void MoveElements(void* a_data, std::uint32_t a_dst, std::uint32_t a_src, std::uint32_t a_count, std::uint32_t a_elemSize);

    std::uint32_t m_size;  // 0x00
};

struct Array3203a0 : public AllocBase3203a0, public ArrayBase3203a0
{
    ~Array3203a0()
    {
        if (m_data)
        {
            Deallocate();
            m_size = 0;
        }
    }

    void RemoveAt(std::uint32_t a_index)
    {
        const std::uint32_t tail = m_size - a_index - 1;
        const std::uint32_t moveCount = (tail < 1u) ? tail : 1u;
        MoveElements(m_data, a_index, m_size - moveCount, moveCount, sizeof(void*));
        --m_size;
    }
};
static_assert(sizeof(Array3203a0) == 0x18, "Array3203a0 size");

class Obj3203a0
{
public:
    void FlushPending();

    std::uint64_t unk00[4];      // 0x00
    Array3203a0 m_items;         // 0x20
    Array3203a0* m_overflow;     // 0x38
    std::uint32_t m_pending;     // 0x40
};
static_assert(offsetof(Obj3203a0, m_items) == 0x20, "m_items offset");
static_assert(offsetof(Obj3203a0, m_overflow) == 0x38, "m_overflow offset");
static_assert(offsetof(Obj3203a0, m_pending) == 0x40, "m_pending offset");
