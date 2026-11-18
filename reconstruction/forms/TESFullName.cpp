// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x146720 TESFullName::GetFullName
#include "TESFullName.h"

void TESFullName::ClearDataComponent()
{
}

std::uint32_t TESFullName::GetFullNameLength() const
{
    return BSFixedStringLength(&fullName);
}

const char* TESFullName::GetFullName() const
{
    return fullName.data();
}
