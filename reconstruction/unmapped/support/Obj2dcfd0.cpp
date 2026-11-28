// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2dcfd0::RemoveAt, treated as adapted: shaped like NiTMapBase::RemoveAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:92
// SPDX-License-Identifier: CC0-1.0
// 0x2dcfd0 Obj2dcfd0::RemoveAt
#include "Obj2dcfd0.h"

// Guess: remove the hash-map bucket entry matching a_key and release it.
bool Obj2dcfd0::RemoveAt(std::uint64_t a_key)
{
    const std::uint32_t index = HashIndex(a_key);
    Entry2dcfd0* entry = m_buckets[index];
    if (entry)
    {
        if (KeyEqual(a_key, entry->m_key))
        {
            m_buckets[index] = entry->m_next;
            ClearValue(entry);
            DeleteEntry(entry);
            --m_count;
            return true;
        }

        Entry2dcfd0* prev = entry;
        Entry2dcfd0* cur = entry->m_next;
        while (cur)
        {
            if (KeyEqual(a_key, cur->m_key))
            {
                prev->m_next = cur->m_next;
                ClearValue(cur);
                DeleteEntry(cur);
                --m_count;
                return true;
            }
            prev = cur;
            cur = cur->m_next;
        }
    }

    return false;
}
