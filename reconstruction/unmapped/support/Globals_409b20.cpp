// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_004d31c0::hkpEntityListener::EntityShapeSetCallback.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:6562
// 0x409b20 f3m_004d31c0::hkpEntityListener::EntityShapeSetCallback
#include "Globals_409b20.h"

namespace f3m_004d31c0 {
void hkpEntityListener::EntityShapeSetCallback(Argument867* argument) {
    if (argument->count08) {
        slot08(argument);
        slot04(argument);
    }
}
}
