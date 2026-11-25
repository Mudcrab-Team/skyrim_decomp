// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function449350 and Function449370.
// BGSAIWorldLocationInteriorCell: EXE_RTTI
// Slot13, Function449350, Function449370, LocationCellHolder, cell, unknown00: GUESS(low)
#pragma once
#include <cstdint>

namespace ReconstructedBGSAIWorldLocationInteriorCell {

#include <cstdint>

struct LocationCellHolder
{
    std::uint8_t unknown00[0x60];
    void* cell;
};

class BGSAIWorldLocationInteriorCell
{
public:
    float Function449800() const;

public:
    float Function4497e0() const;

public:
    float Function4497c0() const;

public:
    virtual std::uint8_t Slot13() const;
    float Function449350(const LocationCellHolder* a_target) const;
    bool Function449370(const LocationCellHolder* a_target) const;

    void* cell;
};

extern const float unknownLocationConstant1b5be28;
extern const float unknownLocationConstant17ed6a8;
extern const float unknownLocationConstant18c40c0;

}
