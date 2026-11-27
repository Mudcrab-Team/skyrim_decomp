// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSFurnitureMarkerNode: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// BSFurnitureMarkerNode::Functionff13a0: GUESS(low)
// BSFurnitureMarkerNode::markers, MarkerEntryff13a0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct MarkerEntryff13a0 { float values[5]; };

class BSFurnitureMarkerNode
{
public:
    MarkerEntryff13a0* Functionff13a0(std::uint32_t index);
    std::uint8_t unknown0[24];
    MarkerEntryff13a0* markers;
};
static_assert(offsetof(BSFurnitureMarkerNode, markers) == 24, "field offset");
