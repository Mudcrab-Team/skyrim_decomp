// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit, one-line bit test)
// IsTemporaryFormID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CombatInventoryItem, Function82cdb0, TESForm, BGSSaveLoadGame, gBGSSaveLoadGame, TestBit, unk1A, unk340: GUESS(low)
#pragma once

#include <cstdint>

class TESForm
{
public:
    bool IsTemporaryFormID();  // callee, matched elsewhere

    char unk00[0x1A];
    std::uint8_t unk1A;
};

class BGSSaveLoadGame
{
public:
    char unk00[0x340];
    std::uint32_t unk340;
};

extern BGSSaveLoadGame* gBGSSaveLoadGame;  // data at 0x3223e18

// TestBit: GUESS(low); flag-word bit test by bit index, word taken by value
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class CombatInventoryItem
{
public:
    static bool Function82cdb0(TESForm* a_form);  // compared: 0x82cdb0
};
