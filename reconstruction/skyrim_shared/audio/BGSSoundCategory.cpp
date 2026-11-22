// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x3299e0 BGSSoundCategory::SetCategoryAttenuation
// 0x329970 BGSSoundCategory::SetCategoryFrequency
// 0x329790 BGSSoundCategory::InitializeData
// 0x329920 BGSSoundCategory::GetCategoryFrequency
// 0x3298d0 BGSSoundCategory::SetCategoryVolume
#include "BGSSoundCategory.h"

void BGSSoundCategory::SetCategoryAttenuation(std::uint16_t a_value)
{
    RawAt<std::uint16_t>(this, 0x1a) = a_value;
}

void BGSSoundCategory::SetCategoryFrequency(float a_value)
{
    RawAt<float>(this, 0x24) = a_value;
}

void BGSSoundCategory::InitializeData()
{
    RawAt<std::uint32_t>(this, 0x4c) = 0xffffffff;
    RawAt<std::uint32_t>(this, 0x38) = 0;
    RawAt<std::uint64_t>(this, 0x40) = 0;
}
