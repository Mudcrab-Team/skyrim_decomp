// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Array3203a0::~Array3203a0 and RemoveAt, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::erase (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:525, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3203a0 Obj3203a0::FlushPending
#include "Obj3203a0.h"

namespace
{
void TrimTail(Array3203a0& a_items, std::uint32_t a_index, std::uint32_t& a_pending)
{
    while (a_pending != 0)
    {
        a_items.RemoveAt(a_index);
        --a_pending;
    }
}
}

// Guess: discard the overflow array and remove the remaining pending tail entries.
void Obj3203a0::FlushPending()
{
    if (m_overflow)
    {
        m_pending -= m_overflow->m_size;
        delete m_overflow;
        m_overflow = nullptr;
    }

    TrimTail(m_items, m_items.m_size - m_pending, m_pending);
}
