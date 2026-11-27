// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpSingleShapeContainerCF58::AddChildShapeToCollector.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp:63
// 0xb46bf0 hkpSingleShapeContainerCF58::AddChildShapeToCollector
#include "Globals_b46bf0.h"

void hkpSingleShapeContainerCF58::AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector,
                                                           const hkClassCF58* pkClass) const throw()
{
    pkCollector->addChildObject("ChildShape", m_pContainedShape, 0);
    Func00c90360(pkCollector, &Data01268910);
}
