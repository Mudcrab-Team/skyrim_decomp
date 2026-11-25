// Source exposure: mixed
// Code origin: original reconstruction from the pinned image listing, shaped after the sibling.
// 0x227330 GridCellArray::Detach
// Adapted bodies: GridCellArray::Detach follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/gridcell.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/gridcell.cpp:50
#include "GridCellArray_227330.h"

void GridCellArray::Detach(std::uint32_t a_x, std::uint32_t a_y)
{
    TESObjectCELL** cell = GetCellSlot(a_x, a_y);
    if (*cell) {
        (*cell)->Detach(true);
        ClearItem(a_x, a_y);
    }
}
