// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1cb6a0 TESFile::GetInteriorOffsetForCell
// Adapted bodies: none
#include "TESFile_1cb6a0.h"

// Looks up the stored file offset for an interior cell by form ID.
std::uint32_t TESFile::GetInteriorOffsetForCell(const TESObjectCELL* a_cell) const
{
    InteriorCellOffsetData* data = interiorCellOffsetData;
    std::uint32_t result = 0;
    for (std::uint32_t i = 0; result == 0 && i < data->count; ++i) {
        InteriorCellOffsetEntry& entry = data->entries[i];
        if (entry.formID == a_cell->formID) {
            result = entry.offset;
        }
    }
    return result;
}
