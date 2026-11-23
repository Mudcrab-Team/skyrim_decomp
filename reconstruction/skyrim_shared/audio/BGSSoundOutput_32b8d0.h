// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSSoundOutput::DoGetSupportsMonitor: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// Function55a430, Function55a420, TestBit, unk00, flagWord: GUESS(low)
// Adapted bodies: TestBit, a one-line bit test close to a sibling helper (CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

std::uint32_t Function55a430();
std::uint32_t Function55a420();

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class BGSSoundOutput
{
public:
    virtual void unk00();
    std::uint32_t flagWord;

protected:
    virtual bool DoGetSupportsMonitor(std::uint32_t a_mode) const;  // compared: 0x32b8d0
};
