// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// BGSEntryPointPerkEntry::SetParent: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:105
// BGSEntryPointPerkEntry, BGSEntryPointPerkEntry::SetParent: GUESS(low)
// BGSEntryPointPerkEntry fields: STANDIN GUESS(low)
// 0x3966c0 BGSEntryPointPerkEntry::SetParent
#include "BGSEntryPointPerkEntry.h"
void BGSEntryPointPerkEntry::SetParent(Perk* value) { parent = value; if (functionData) functionData->SetPerk(value); }
