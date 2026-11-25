// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a8a620::Func00a8a620.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3267
// 0xf06b70 Func00a8a620::Func00a8a620
#include "Func00a8a620_f06b70.h"

Func00a8a620::Func00a8a620(unsigned int uiSize)
{
    m_uiSize = uiSize;
    if (uiSize)
        m_pBuffer = NiMalloc(uiSize);
    else
        m_pBuffer = 0;
    m_pCursor = m_pBuffer;
    m_iUsed = 0;
}
