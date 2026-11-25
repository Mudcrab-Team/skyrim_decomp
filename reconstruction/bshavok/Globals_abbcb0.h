// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkFreeList: CRASHLOGGER_PDB(59818@2026.10.24)
// hkFreeList::incrementalFindGarbage: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct hkBoolDD7C
{
    char m_cBooleanValue;
    hkBoolDD7C(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

struct hkFreeListBlockDD7C
{
    hkFreeListBlockDD7C* m_next;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkFreeList
{
  public:
    char padding_0_[16];
    hkFreeListBlockDD7C *m_incrementalBlock;
    hkFreeListBlockDD7C *m_kBlocks;
    hkFreeListBlockDD7C *m_pFreeBlocks;
    int Func00dd7b40(hkFreeListBlockDD7C* pkBlock);
    hkBoolDD7C incrementalFindGarbage(int m_iFreeBlockCount, int& iNumBlocksOut);
};

struct Globals
{
};
