// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// SpellItem::GetRange: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:268
// SpellItem::LoadChunkDataPostProcess: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:128
// SpellItem::SetCastingType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:232
// SpellItem, SpellItem::GetRange: GUESS(low)
// SpellItem fields: STANDIN GUESS(low)
// 0x155780 SpellItem::GetRange
// 0x1558c0 SpellItem::LoadChunkDataPostProcess
// 0x1553e0 SpellItem::SetCastingType
#include "SpellItem.h"
float SpellItem::GetRange() const { return range; }

void SpellItem::LoadChunkDataPostProcess(InputFile* file) { if (file->version < 0x22) castingPerk = nullptr; }

void SpellItem::SetCastingType(int value) { castingType = value; MagicItem::SetCastingType(value); }
