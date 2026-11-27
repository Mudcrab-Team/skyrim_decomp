// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkFreeList::incrementalFindGarbage.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp:665
// 0xabbcb0 hkFreeList::incrementalFindGarbage
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp:456
// Adapted helpers: hkBoolDD7C
#include "Globals_abbcb0.h"

hkBoolDD7C hkFreeList::incrementalFindGarbage(int iMaxBlocks, int& iNumBlocksOut) throw()
{
    int i = 0;
    for (; i < iMaxBlocks; i++)
    {
        if (m_incrementalBlock)
        {
            hkFreeListBlockDD7C* pkBlock = m_incrementalBlock->m_next;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (Func00dd7b40(pkBlock))
            {
                m_incrementalBlock->m_next = pkBlock->m_next;
                pkBlock->m_next = m_pFreeBlocks;
                m_pFreeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
        else
        {
            hkFreeListBlockDD7C* pkBlock = m_kBlocks;
            if (!pkBlock)
            {
                iNumBlocksOut = i;
                m_incrementalBlock = 0;
                return true;
            }
            if (Func00dd7b40(pkBlock))
            {
                m_kBlocks = pkBlock->m_next;
                pkBlock->m_next = m_pFreeBlocks;
                m_pFreeBlocks = pkBlock;
            }
            else
            {
                m_incrementalBlock = pkBlock;
            }
        }
    }
    iNumBlocksOut = i;
    return m_incrementalBlock == 0;
}
