// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// DeletingDestructor117c0b0, DeletingBase117c0b0, unk08, unk10: GUESS(low) STANDIN; community list calls 0x117c0b0 BSScaleformImageLoader::LoadImage, which does not fit a 0x168-byte deleting destructor
#pragma once

#include <cstdint>

class DeletingBase117c0b0
{
public:
    virtual ~DeletingBase117c0b0() {}
};
static_assert(sizeof(DeletingBase117c0b0) == 0x8, "DeletingBase117c0b0 size");

class DeletingDestructor117c0b0 : public DeletingBase117c0b0
{
public:
    DeletingDestructor117c0b0();
    ~DeletingDestructor117c0b0() override {}

    DeletingBase117c0b0 unk08;        // 08
    std::uint8_t        unk10[0x158]; // 10
};
static_assert(sizeof(DeletingDestructor117c0b0) == 0x168, "DeletingDestructor117c0b0 size");
