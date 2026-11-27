// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00db78a0_cls::Func00db78a0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00da0000_o2.cpp:793
// 0xbfe4f0 Func00db78a0_cls::Func00db78a0
#include "Func00db78a0_cls_bfe4f0.h"

void Func00db78a0_cls::Func00db78a0(Func00db78a0_item** apItems, void** apValues)
{
    Func00db78a0_item** p = apItems;
    if (*p == 0)
        return;
    do
    {
        void* item = *(void**)((char*)apValues + ((char*)p - (char*)apItems));
        if (item == 0)
            break;
        void* field = (*p)->m_0c;
        if (field != 0)
            this->vSlot0c(field, item);
        p++;
    } while (*p != 0);
}
