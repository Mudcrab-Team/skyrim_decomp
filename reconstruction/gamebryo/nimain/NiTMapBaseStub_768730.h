// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiTMapBaseStub, NiTMapBaseStub::~NiTMapBaseStub: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once

void NiFree(void*);

namespace fnv_00b656e0 {
class NiTMapBaseStub
{
  public:
    virtual ~NiTMapBaseStub();
    void RemoveAll();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
}
