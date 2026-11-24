// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d481d0::Func00d481d0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp:76
// 0xb2eda0 Func00d481d0::Func00d481d0
#include "Func00d481d0_b2eda0.h"

Func00d481d0::Func00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* apClass)
{
    m_name = name;
    m_pReferencedResource.set(object, apClass);
    m_pClassName = m_pReferencedResource.GetVariantValue() ? m_pReferencedResource.GetVariantValue()->getName() : 0;
}
