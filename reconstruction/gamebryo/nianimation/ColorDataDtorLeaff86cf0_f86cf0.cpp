// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf86cf0 ColorDataDtorLeaff86cf0::~ColorDataDtorLeaff86cf0
#include "ColorDataDtorLeaff86cf0_f86cf0.h"
#include <intrin.h>

ColorDataBasef86cf0::~ColorDataBasef86cf0()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColorDataCountf86cf0);
}
ColorDataDtorLeaff86cf0::ColorDataDtorLeaff86cf0() = default;
ColorDataDtorLeaff86cf0::~ColorDataDtorLeaff86cf0()
{
    if (keys) {
        auto destroy = gColorKeyDestroyersf86cf0[type];
        destroy(keys);
    }
}
