// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func0084e4f0_cls::ReferenceInitialData_Initialize_CREATED.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00840000_od.cpp:2864
// 0x620280 Func0084e4f0_cls::ReferenceInitialData_Initialize_CREATED
#include "Func0084e4f0_cls_620280.h"

void Func0084e4f0_cls::ReferenceInitialData_Initialize_CREATED(void* pSource)
{
    m_00 = BGSNumericIDIndex_GetNumericID(pSource);
    m_04 = BGSNumericIDIndex_GetNumericID((char*)pSource + 0x1c);
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
    m_14 = *(Func0084e4f0_triple*)((char*)pSource + 3);
    m_20 = *(Func0084e4f0_triple*)((char*)pSource + 0xf);
    m_2c = *((unsigned char*)pSource + 0x1b);
}
