// Exposure detail: (assigned pinned-image pack; permitted sibling name and shape study).
// Source exposure: mixed
// Code origin: original draft; later sibling study supplied the method name, not the body.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIWorldLocationCell.cpp:59 (name and shape study).
// SPDX-License-Identifier: CC0-1.0
// BGSAIWorldLocationInteriorCell: EXE_RTTI
// BGSAIWorldLocationInteriorCell::GetWorldLocation: SIBLING(fo4-private@1b765c70, author-permission)
// BGSAIWorldLocationInteriorCell::Location, vtable, interiorCell, coordinateX, coordinateY, coordinateZ, unknown0C: GUESS(low); local names; layout inferred from assigned accesses.
// 0x449390 BGSAIWorldLocationInteriorCell::GetWorldLocation

#pragma once
#include <cstdint>

class BGSAIWorldLocationInteriorCell
{
public:
    struct Location
    {
        float coordinateX;
        float coordinateY;
        float coordinateZ;
        std::uint32_t unknown0C;
        void* interiorCell;
    };
    bool GetWorldLocation(Location& destination) const;
    void* vtable;
    void* interiorCell;
    float coordinateX;
    float coordinateY;
    float coordinateZ;
};
