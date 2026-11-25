// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: A3D370LoadEnum.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nicolordata.cpp:303
// 0xfb4610 A3D370LoadEnum
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nicolordata.cpp:132
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nicolordata.cpp:293
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nicolordata.cpp:299
// Adapted helpers: BinaryRead, A3D370BinaryStreamLoad, A3D370LoadBinary
#include "Globals_fb4610.h"

template <class T> inline void A3D370LoadEnum(A3D370Stream& kStream, T& eValue)
{
    unsigned int uiValue;
    A3D370LoadBinary(kStream, uiValue);
    eValue = (T)uiValue;
}

template void A3D370LoadEnum<enum KeyTypeA3D>(class A3D370Stream &, enum KeyTypeA3D &);
