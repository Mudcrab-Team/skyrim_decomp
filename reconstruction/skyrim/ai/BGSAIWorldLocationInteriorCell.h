// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function449350.
// BGSAIWorldLocationInteriorCell: EXE_RTTI
// Slot13, Function449350, LocationCellHolder, cell, unknown00: GUESS(low)
#pragma once
#include <cstdint>

struct LocationCellHolder
{
    std::uint8_t unknown00[0x60];
    void* cell;
};

class BGSAIWorldLocationInteriorCell
{
public:
    virtual std::uint8_t Slot13() const;
    float Function449350(const LocationCellHolder* a_target) const;

    void* cell;
};
