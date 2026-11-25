// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x71d190 RefLeaf71d190::~RefLeaf71d190
#include "RefLeaf71d190_71d190.h"
#include <intrin.h>


LeafBase71d190::~LeafBase71d190()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gCount71d190);
}

RefLeaf71d190::RefLeaf71d190() = default;
RefLeaf71d190::~RefLeaf71d190() = default;
