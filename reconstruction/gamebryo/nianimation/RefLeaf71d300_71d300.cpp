// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x71d300 RefLeaf71d300::~RefLeaf71d300
#include "RefLeaf71d300_71d300.h"
#include <intrin.h>


LeafBase71d300::~LeafBase71d300()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gCount71d300);
}

RefLeaf71d300::RefLeaf71d300() = default;
RefLeaf71d300::~RefLeaf71d300() = default;
