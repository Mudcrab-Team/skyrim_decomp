// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfa1360 ExtraLeaffa1360::~ExtraLeaffa1360
#include "ExtraLeaffa1360_fa1360.h"
#include <intrin.h>


ExtraLeafBase::~ExtraLeafBase()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gExtraLeafCount);
}

ExtraLeaffa1360::ExtraLeaffa1360() = default;
ExtraLeaffa1360::~ExtraLeaffa1360() = default;
