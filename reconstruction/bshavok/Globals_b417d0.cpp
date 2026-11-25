// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpMoppBvTreeShape::Func2_140A62F10.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp:144
// 0xb417d0 hkpMoppBvTreeShape::Func2_140A62F10
#include "Globals_b417d0.h"

void hkpMoppBvTreeShape::Func2_140A62F10(hkStatisticsCollectorD543* pkCollector,
                                                              const hkClassD543* pkClass) const throw()
{
    pkCollector->addChildObject("Mesh", m_pContainedShape, 0);
    pkCollector->addChildObject("Mopp", m_pMoppCode, 0);
    Func00c90360(pkCollector, &Data01269c8c);
}
