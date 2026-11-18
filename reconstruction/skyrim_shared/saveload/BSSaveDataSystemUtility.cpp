// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x159af80 BSSaveDataSystemUtility::Unk_0B
// 0x159ab30 BSSaveDataSystemUtility::Unk_0A
#include "BSSaveDataSystemUtility.h"

std::uint64_t* BSSaveDataSystemUtility::Unk_0B(std::uint64_t* a_out)
{
    *a_out = 0;
    return a_out;
}

std::uint32_t BSSaveDataSystemUtility::Unk_0A(void* a_obj)
{
    std::uint32_t value = 0;
    LookupValue(a_obj, &value);
    return value;
}

// RVA 0x159a9e0, 3 bytes: returns true.
bool BSSaveDataSystemUtility::Unk_08()
{
    return true;
}

// RVA 0x159a9f0, 3 bytes: returns true.
bool BSSaveDataSystemUtility::Unk_07()
{
    return true;
}

// RVA 0x159aa00, 3 bytes: an empty slot body.
void BSSaveDataSystemUtility::Unk_05()
{
}
