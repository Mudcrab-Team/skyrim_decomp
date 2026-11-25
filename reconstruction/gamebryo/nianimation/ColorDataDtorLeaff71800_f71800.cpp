// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf71800 ColorDataDtorLeaff71800::~ColorDataDtorLeaff71800
#include "ColorDataDtorLeaff71800_f71800.h"
#include <intrin.h>

ColorDataBasef71800::~ColorDataBasef71800()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColorDataCountf71800);
}
ColorDataDtorLeaff71800::~ColorDataDtorLeaff71800()
{
    if (keys) {
        gColorKeyDestroyersf71800[type](keys);
    }
}
