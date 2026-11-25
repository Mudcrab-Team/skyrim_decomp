// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkStringBuf::pathBasename.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d60000_o2.cpp:940
// 0xaae4d0 hkStringBuf::pathBasename
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00d60000_o2.cpp:883
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00d60000_o2.cpp:872
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d60000_o2.cpp:921
// Adapted helpers: pathBasename, max2
// CI hash: 0xaae4d0 ?pathBasename@hkStringBuf@@QEAAXXZ
#include "Globals_aae4d0.h"

void hkStringBuf::pathBasename()
{
    int iLastSeparator =
        hkMathD618::max2(FindLastCharInRange('\\', 0, 0x7fffffff), FindLastCharInRange('/', 0, 0x7fffffff));
    if (iLastSeparator >= 0)
        RemoveFront(iLastSeparator + 1);
}
