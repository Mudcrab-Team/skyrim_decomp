// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ahkpCharacterProxy: CRASHLOGGER_PDB(59818@2026.10.24)
// ahkpCharacterProxy::Routine140AC22E0: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, vslot_0_, vslot_1_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct CAD4C0Listener;



struct ahkpCharacterProxy;

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct CAD4C0Listener
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void notify(ahkpCharacterProxy* owner, void* data);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ahkpCharacterProxy
{
  public:
    char padding_0_[200];
    CAD4C0Listener **m_kListeners;
    int m_numListeners;
    void Routine140AC22E0(void* data);
};

struct Globals
{
};
