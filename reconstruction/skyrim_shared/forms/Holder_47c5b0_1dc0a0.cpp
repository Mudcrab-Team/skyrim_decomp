// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Holder_47c5b0::FormComponentCollection_ClearDataAllComponents.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/formcomponentcollection.cpp:152
// 0x1dc0a0 Holder_47c5b0::FormComponentCollection_ClearDataAllComponents
#include "Holder_47c5b0_1dc0a0.h"

void Holder_47c5b0::FormComponentCollection_ClearDataAllComponents()
{
    int i;
    for (i = 0; i < 38; i++)
    {
        if (arr[i] != 0)
            arr[i]->f1();
    }
}
