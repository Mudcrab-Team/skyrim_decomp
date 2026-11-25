// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: S_cb2110_Foo::Func00cb2110.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/math/matrix/hktransform.cpp:86
// 0xaa4660 S_cb2110_Foo::Func00cb2110
#include "S_cb2110_Foo_aa4660.h"

bool* S_cb2110_Foo::Func00cb2110(bool* result)
{
    bool value1;
    bool value2;
    bool value;

    if (*unk30.CheckFloatsFinite(&value1) && *Func00cb2d70(&value2))
    {
        value = true;
    }
    else
    {
        value = false;
    }
    *result = value;
    return result;
}
