// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf009d0 RefLeaff009d0::~RefLeaff009d0
#include "RefLeaff009d0_f009d0.h"
#include <intrin.h>


LeafBasef009d0::~LeafBasef009d0()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gCountf009d0);
}

RefLeaff009d0::RefLeaff009d0() = default;
RefLeaff009d0::~RefLeaff009d0() = default;
