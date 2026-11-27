// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: SaveKeyArray.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a20000_o2.cpp:1047
// 0xf8e630 SaveKeyArray
#include "Globals_f8e630.h"

void SaveKeyArray(NiStream& kStream, A28260Key* pkKeys, unsigned int uiNumKeys)
{
    for (unsigned int ui = 0; ui < uiNumKeys; ui++)
    {
        A28260Key* pkKey = &pkKeys[ui];
        ApplyAnimToTarget(kStream, pkKey);
        pkKey->m_kColor0.SaveBinary(kStream);
        pkKey->m_kColor1.SaveBinary(kStream);
    }
}
