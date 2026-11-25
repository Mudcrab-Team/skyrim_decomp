// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_007cf040::Obj7cf040::Func007cf040.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_007c0000_o2.cpp:3568
// 0x8080c0 f3m_007cf040::Obj7cf040::Func007cf040
#include "Obj7cf040_8080c0.h"

namespace f3m_007cf040 {
void Obj7cf040::Func007cf040(Ref7cf040* r)
{
    if (sub) {
        if (sub->unk3c == 1)
            if (r) sub->Func005080b0(r->v116()); else sub->Func005080b0(0);
        if (sub->unk40 == 1)
            if (r) sub->Func005081d0(r->v116()); else sub->Func005081d0(0);
    }
    ref = r;
}
}
