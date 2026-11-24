// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00cf6170.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp:325
// 0xaa8f20 Func00cf6170
#include "Globals_aa8f20.h"

unsigned char* Func00cf6170(unsigned char* result, Func00d46f70_Obj* object)
{
    if (object != 0)
    {
        do
        {
            if (object == &Data01268748)
                break;

            if (object->Func00d46f70() > 0)
            {
                *result = 1;
                return result;
            }

            object = object->Func00d46d50();
        } while (object != 0);
    }

    *result = 0;
    return result;
}
