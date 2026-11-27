// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00b656e0::NiTMapBaseStub::~NiTMapBaseStub.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderaccumulator.cpp:9
// 0xf02950 fnv_00b656e0::NiTMapBaseStub::~NiTMapBaseStub
// CI hash: 0xf02950 ??1NiTMapBaseStub@fnv_00b656e0@@UEAA@XZ
#include "NiTMapBaseStub_f02950.h"

namespace fnv_00b656e0 {
NiTMapBaseStub::~NiTMapBaseStub()
{
    RemoveAll();
    NiFree(m_ppkHashTable);
}
}
