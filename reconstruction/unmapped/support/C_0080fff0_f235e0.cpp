// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: C_0080fff0::Func0080fff0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3twins/small_11060602_00.cpp:47
// 0xf235e0 C_0080fff0::Func0080fff0
#include "C_0080fff0_f235e0.h"

char C_0080fff0::Func0080fff0(C_0080fff0* o)
{
    if (!Func0084a7c0(o) || !o)
        return 0;
    R_0080fff0* r = o->v2();
    for (;; r = r->p)
    {
        if (!r)
            return 0;
        if (r == &Data0108ec3c)
            break;
    }
    if (o->f28 != f28)
        return 0;
    if (o->f24 != f24)
        return 0;
    Q_0080fff0* a = o->f2c;
    if (a)
    {
        Q_0080fff0* b = f2c;
        if (b)
        {
            int ra = a->v3();
            int rb = b->v3();
            if (ra == rb)
                goto ok;
            return 0;
        }
    }
    if (a != f2c)
        return 0;
ok:
    return 1;
}
