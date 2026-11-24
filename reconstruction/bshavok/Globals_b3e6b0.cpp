// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpShapeContainer::getNumChildShapes_140A5FD80.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/shape/hkpshapecontainer.cpp:25
// 0xb3e6b0 hkpShapeContainer::getNumChildShapes_140A5FD80
// CI hash: 0xb3e6b0 ?getNumChildShapes_140A5FD80@hkpShapeContainer@@QEAAHXZ
#include "Globals_b3e6b0.h"

int hkpShapeContainer::getNumChildShapes_140A5FD80()
{
    int count = 0;
    int child = Func00d1f1e0_2();

    while (child != -1)
    {
        ++count;
        child = Func00d1f1e0_3(child);
    }

    return count;
}
