// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0047b6e0::Owner_0047b6e0::Func0047b6e0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:6563
// 0x227970 f3m_0047b6e0::Owner_0047b6e0::Func0047b6e0
#include "GridCellArray_227970.h"

namespace f3m_0047b6e0 {
void Owner_0047b6e0::Func0047b6e0()
{
    unsigned int i = 0;
    while (i < unk0C) {
        unsigned int j = 0;
        while (j < unk0C) {
            Elem_0047b6e0* e = *((i < unk0C && j < unk0C) ? &unk10[i * unk0C + j] : 0);
            if (e) {
                e->Func004d70f0();
            }
            ++j;
        }
        ++i;
    }
}
}
