// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x38ea80 BGSEntryPointFunctionDataActivateChoice::Unk_05
// 0x38ea90 BGSEntryPointFunctionDataActivateChoice::SetPerk
// 0x38eaa0 BGSEntryPointFunctionDataActivateChoice::GetPerk
#include "BGSEntryPointFunctionDataActivateChoice.h"

std::uint16_t BGSEntryPointFunctionDataActivateChoice::Unk_05()
{
    return field22;
}

void BGSEntryPointFunctionDataActivateChoice::SetPerk(BGSPerk* a_perk)
{
    perk10 = a_perk;
}

BGSPerk* BGSEntryPointFunctionDataActivateChoice::GetPerk()
{
    return perk10;
}
