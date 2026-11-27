// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: D06D50Finder::FindClass.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp:163
// 0xab07e0 D06D50Finder::FindClass
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/common/base/debugutil/statisticscollector/hkstatisticscollector.cpp:172
#include "D06D50Finder_ab07e0.h"

const D06D50Class* D06D50Finder::FindClass(const D06D50Object* object) const
{
    if (object)
    {
        const D06D50Class* pClass = object->GetClassType();
        if (pClass)
            return pClass;
        if (m_registry)
        {
            pClass = m_registry->GetClassFromName(object);
            if (pClass)
                return pClass;
        }
    }
    return 0;
}
