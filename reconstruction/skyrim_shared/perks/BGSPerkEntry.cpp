// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSPerkEntry: EXE_RTTI
// GetID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x395b20 BGSPerkEntry::GetID
#include "BGSPerkEntry.h"
// GetID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BGSPerkEntry::GetID() const
{
    return 0xffff;
}

void BGSPerkEntry::SetParent(BGSPerk*)
{
}

bool BGSPerkEntry::CheckConditionFilters(std::uint32_t, void*)
{
    return false;
}

void BGSPerkEntry::ClearData()
{
}
