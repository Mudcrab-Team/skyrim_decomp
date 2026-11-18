// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSEntryPointPerkEntry::GetID: SIBLING(fo4-private@1b765c70, author-permission); adapted to target conditional virtual call.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:113
// names: GUESS(low); function and virtual call names are unverified.
// 0x3966e0 BGSEntryPointPerkEntry::GetID
#include "BGSEntryPointPerkEntry.h"
unsigned short BGSEntryPointPerkEntry::GetID() const { return functionData ? functionData->GetID() : 0xffff; }
