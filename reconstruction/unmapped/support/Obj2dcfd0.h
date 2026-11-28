// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2dcfd0::RemoveAt, treated as adapted: shaped like NiTMapBase::RemoveAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:92
// SPDX-License-Identifier: CC0-1.0
// Entry2dcfd0, Obj2dcfd0, Obj2dcfd0::RemoveAt: GUESS(low)
#pragma once

#include <cstdint>

struct Entry2dcfd0
{
    Entry2dcfd0* m_next;  // 0x00
    std::uint64_t m_key;  // 0x08
};

class Obj2dcfd0
{
public:
    virtual ~Obj2dcfd0();
    virtual std::uint32_t HashIndex(std::uint64_t a_key) const;
    virtual bool KeyEqual(std::uint64_t a_lhs, std::uint64_t a_rhs) const;
    virtual void VFunc03();
    virtual void ClearValue(Entry2dcfd0* a_entry);
    virtual void VFunc05();
    virtual void DeleteEntry(Entry2dcfd0* a_entry);

    bool RemoveAt(std::uint64_t a_key);

    std::uint32_t m_hashSize;   // 0x08
    Entry2dcfd0** m_buckets;    // 0x10
    std::uint32_t m_count;      // 0x18
};
