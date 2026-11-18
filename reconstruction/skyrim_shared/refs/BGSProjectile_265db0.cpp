// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// BGSProjectile::ClearData: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSProjectile.cpp:58
// BGSProjectile, BGSProjectile::ClearData: GUESS(low)
// BGSProjectile fields: STANDIN GUESS(low)
// 0x265db0 BGSProjectile::ClearData
#include "BGSProjectile_265db0.h"
void BGSProjectile::ClearData() { muzzleFlashModel.ClearDataComponent(); }
