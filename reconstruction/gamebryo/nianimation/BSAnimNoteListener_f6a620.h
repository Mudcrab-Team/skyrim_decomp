// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSAnimNoteListener: CRASHLOGGER_PDB(59818@2026.10.24)
// BSAnimNoteListener::Update: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
#pragma once

struct HandlerArg;
struct HandlerEntry;
struct HandlerObject;


class HandlerObject
{
  public:
    virtual void unk00();
    virtual void Handle(void* pArg);
};

struct HandlerEntry
{
    unsigned int m_key;
    HandlerObject* m_pEntryObject;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct HandlerArg
{
  public:
    char padding_0_[16];
    unsigned int m_key;
};

class BSAnimNoteListener
{
  public:
    int unk00;
    HandlerEntry** m_ppEntries;
    unsigned short unk08;
    unsigned short m_uiItemCount;

    void Update(HandlerArg* a1);
};
