// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpCollisionDispatcher: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpCollisionDispatcher::Routine140B25D00: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct CFB240ContactMgrFactory;


struct CFB240ContactMgrFactory
{
    void RetainReference() const;
    void removeReference() const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkpCollisionDispatcher
{
  public:
    char padding_0_[24];
    CFB240ContactMgrFactory *m_apContactMgrFactoriesByResponsePair[8][8];
    void Routine140B25D00(CFB240ContactMgrFactory* fac, int responseA);
};

struct Globals
{
};
