// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00dbb940::hkDataClassNative::getParent.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/serialize/data/native/hkdataobjectnative.cpp:185
// 0xc65710 fnv_00dbb940::hkDataClassNative::getParent
// CI hash: 0xc65710 ?getParent@hkDataClassNative@fnv_00dbb940@@QEAAHXZ
#include "Globals_c65710.h"

namespace fnv_00dbb940 {
int hkDataClassNative::getParent()
{
    D481D0Class* parent = m_0C->Func00d46d50();

    if (parent)
    {
        return m_10->Func00dbb940_9(parent->getName());
    }
    else
    {
        return 0;
    }
}
}
