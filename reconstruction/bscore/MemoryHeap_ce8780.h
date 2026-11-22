// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MemoryHeap, BlockIsInHeap: GUESS(low) SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); the class is the placeholder owner
// unk0A, unk00 to unk09: GUESS(low); virtual slots as called by this one function
// TestBit64: GUESS(low); a flag-word bit test by bit index, taking the word by value
#pragma once

#include <cstdint>

inline bool TestBit64(std::uint64_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class MemoryHeap
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual bool unk0A() const;  // 0A

    bool BlockIsInHeap(const void* a_block) const;  // compared: 0xce8780
};
