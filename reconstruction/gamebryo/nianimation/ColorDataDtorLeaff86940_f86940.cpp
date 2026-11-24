// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf86940 ColorDataDtorLeaff86940::~ColorDataDtorLeaff86940
#include "ColorDataDtorLeaff86940_f86940.h"
#include <intrin.h>

ColorDataBasef86940::~ColorDataBasef86940()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColorDataCountf86940);
}
ColorDataDtorLeaff86940::~ColorDataDtorLeaff86940()
{
    if (keys) {
        gColorKeyDestroyersf86940[type](keys);
    }
}
