// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiAVObject::HasTransformController.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niavobject.cpp:389
// 0xee11e0 NiAVObject::HasTransformController
#include "NiAVObject_ee11e0.h"

bool NiAVObject::HasTransformController()
{
    NiAVObject* p = m_pHeadNode;
    while (p)
    {
        if (p->v39())
            return true;
        p = p->m_next;
    }
    return false;
}
