// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d2b360.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d20000_o2.cpp:1864
// 0xaa6190 Func00d2b360
#include "Globals_aa6190.h"

const char* Func00d2b360(const char* path, PathHelper* aPathHelper)
{
    aPathHelper->Func00d61c10(path);
    aPathHelper->ReplaceChar('\\', '/', 1);
    aPathHelper->Func00d62190("/./", "/", 1);
    if (aPathHelper->Func00d61560("./"))
        aPathHelper->RemoveFront(2);
    return aPathHelper->m_data;
}
