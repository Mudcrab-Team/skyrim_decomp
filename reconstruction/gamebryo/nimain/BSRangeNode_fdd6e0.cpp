// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00aa9880::Task2735::BSRangeNode::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:20317
// 0xfdd6e0 f3m_00aa9880::Task2735::BSRangeNode::IsEqual
#include "BSRangeNode_fdd6e0.h"

namespace f3m_00aa9880 {
namespace Task2735 {
char BSRangeNode::IsEqual(BSRangeNode* other) {
    bool r7 = Func0082e460(other);
    if (r7) {
        BSRangeNode* oB = other;
        unsigned char a8, b, c5, d, e, f7;
        r7 = ((a8 = unkAE, b = oB->unkAE, a8 == b) && (c5 = unkAF, d = oB->unkAF, c5 == d) && (e = unkAD, f7 = oB->unkAD, e == f7)) ? 1 : 0;
    }
    return r7;
}
}
}
