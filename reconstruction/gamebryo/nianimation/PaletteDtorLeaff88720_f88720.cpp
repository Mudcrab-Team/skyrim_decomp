// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf88720 PaletteDtorLeaff88720::~PaletteDtorLeaff88720
#include "PaletteDtorLeaff88720_f88720.h"
#include <intrin.h>

PaletteDtorBasef88720::~PaletteDtorBasef88720()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gPaletteCountf88720);
}
PaletteDtorLeaff88720::PaletteDtorLeaff88720() = default;
PaletteDtorLeaff88720::~PaletteDtorLeaff88720()
{
    ReleasePaletteMemoryf88720(data);
}
