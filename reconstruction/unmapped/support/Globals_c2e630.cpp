// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: RegisterAll.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00ca0000_o2.cpp:9835
// 0xc2e630 RegisterAll
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ca0000_o2.cpp:9210
// Adapted helpers: CBFC10Bool
#include "Globals_c2e630.h"

void RegisterAll(CBFC10Registry* pkRegistry)
{
    pkRegistry->Set(false);
    CBFC10RegisterA(pkRegistry);
    CBFC10RegisterB(pkRegistry);
    CBFC10RegisterC(pkRegistry);
    CBFC10RegisterD(pkRegistry);
    CBFC10RegisterE(pkRegistry);
    pkRegistry->Set(true);
}
