// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf60ca0 ColorDataLeaff60ca0::~ColorDataLeaff60ca0
#include "ColorDataLeaff60ca0_f60ca0.h"
#include <intrin.h>

ColorDataBase::~ColorDataBase()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColorObjectCount);
}

ColorDataLeaff60ca0::~ColorDataLeaff60ca0()
{
    if (keys) {
        gColorDeleteTable[type](keys);
    }
}
