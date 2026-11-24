// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xedd080 RefLeafedd080::~RefLeafedd080
#include "RefLeafedd080_edd080.h"
#include <intrin.h>


LeafBaseedd080::~LeafBaseedd080()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gCountedd080);
}

RefLeafedd080::RefLeafedd080() = default;
RefLeafedd080::~RefLeafedd080() = default;
