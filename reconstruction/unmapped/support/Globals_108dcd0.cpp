// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkAvoidBox::Func15_140DE6C30.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00e20000_o2.cpp:2144
// 0x108dcd0 hkAvoidBox::Func15_140DE6C30
#include "Globals_108dcd0.h"

int hkAvoidBox::Func15_140DE6C30()
{
    ClassLayout_91ab10* self = (ClassLayout_91ab10*)this;
    int n = self->m_count;
    int i = 0;
    if (n > 0)
    {
        for (;;)
        {
            int r = self->s38(i);
            i++;
            if (i >= n)
                return r;
        }
    }
}
