// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf61f00 ColorDataLeaff61f00::~ColorDataLeaff61f00
#include "ColorDataLeaff61f00_f61f00.h"
#include <intrin.h>

ColorDataBasef61f00::~ColorDataBasef61f00()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gColorObjectCountf61f00);
}

ColorDataLeaff61f00::~ColorDataLeaff61f00()
{
    if (keys) {
        gColorDeletef61f00Table[type](keys);
    }
}
