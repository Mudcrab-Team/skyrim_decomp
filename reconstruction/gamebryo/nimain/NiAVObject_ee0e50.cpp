// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiAVObject::UpdateTransformAndBounds.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niavobject.cpp:717
// 0xee0e50 NiAVObject::UpdateTransformAndBounds
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/niavobject.cpp:378
#include "NiAVObject_ee0e50.h"

void NiAVObject::UpdateTransformAndBounds(void* pArg)
{
    unsigned char flags = (unsigned char)(m_flags >> 2);
    if (flags & 1)
    {
        v46(pArg);
        v47();
    }
}
