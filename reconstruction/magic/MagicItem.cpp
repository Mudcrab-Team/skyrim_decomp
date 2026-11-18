// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x146770 MagicItem::GetMaxEffectCount
// 0x14e7c0 MagicItem::IsMedicine
// 0x14e830 Leaf14e830::Invoke
#include "MagicItem.h"

std::uint32_t MagicItem::GetMaxEffectCount() const
{
    return 0;
}

bool MagicItem::IsMedicine() const
{
    return false;
}

void MagicItem::LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID)
{
}
