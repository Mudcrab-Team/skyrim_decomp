// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ahkpCharacterProxy: CRASHLOGGER_PDB(59818@2026.10.24)
// ahkpCharacterProxy::Routine140AC2340: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct CAD4C0Listener;



struct ahkpCharacterProxy;

struct CAD4C0Listener {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void notify(ahkpCharacterProxy* owner, void* data);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ahkpCharacterProxy
{
  public:
    char padding_0_[200];
    CAD4C0Listener **m_kListeners;
    int m_numListeners;
    void Routine140AC2340(void* data);
};

struct Globals
{
};
