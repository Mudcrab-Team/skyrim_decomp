// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00aa1fd0_cls::AdvanceChars.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00aa0000_o2.cpp:394
// 0xeae250 Func00aa1fd0_cls::AdvanceChars
#include "Func00aa1fd0_cls_eae250.h"

unsigned int Func00aa1fd0_cls::AdvanceChars(char* s)
{
    unsigned int count = 0;
    if (*s != 0)
    {
        do
        {
            int out = 1;
            int r = m_0c(this, s, 1, &out, 1);
            m_04 += r;
            s++;
            if (r != 1)
            {
                break;
            }
            count++;
        } while (*s != 0);
    }
    return count;
}
