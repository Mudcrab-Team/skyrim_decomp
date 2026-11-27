// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00a8a620: GUESS(low); placeholder name
// Func00a8a620::Func00a8a620: GUESS(low); placeholder name
#pragma once

void* NiMalloc(unsigned int uiSize);

struct Func00a8a620 {
    unsigned int m_uiSize;
    void* m_pBuffer;
    void* m_pCursor;
    int m_iUsed;

    Func00a8a620(unsigned int uiSize);
};
