// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00aae3a0::Func00aae3a0_Obj::Func00aae3a0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:26467
// 0xfefb50 f3m_00aae3a0::Func00aae3a0_Obj::Func00aae3a0
#include "Func00aae3a0_Obj_fefb50.h"

namespace f3m_00aae3a0 {
void Func00aae3a0_Obj::Func00aae3a0()
{
    unsigned int count = unkA6;
    unsigned int index = 0;

    while (index < count)
    {
        Func00aae3a0_Node* node = unkA0[index];
        if (node != 0)
            node->Func00ab6f00();
        ++index;
    }
}
}
