// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiUnionBV::Func1_140CA6860.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_nooy_variant.cpp:510
// 0xf3d4e0 NiUnionBV::Func1_140CA6860
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp:265
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00940000_o2.cpp:1790
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp:798
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp:1315
// Adapted helpers: BinaryWrite, SerializeValue
#include "NiUnionBV_f3d4e0.h"

void NiUnionBV::Func1_140CA6860(NiStream& kStream)
{
    SaveValueToStream(kStream);

    unsigned int ItemUpdateArray = m_usElementCount;
    SerializeValue(*kStream.m_pBackingStream, ItemUpdateArray);

    for (unsigned int i = 0; i < m_usElementCount; i++)
    {
        NiSavable* pkObj = m_ppSavableObjects[i];
        if (pkObj)
            pkObj->SaveBinary(kStream);
    }
}
