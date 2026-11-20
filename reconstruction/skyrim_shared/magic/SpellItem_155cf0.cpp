// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x154d10 Leaf154d10::Invoke
// 0x155cf0 SpellItem::GetCastingType
// 0x155d00 SpellItem::GetSpellType
#include "SpellItem_155cf0.h"

std::uint32_t SpellItem::GetDataSize() const
{
    return 0x28;
}

MagicSystem::CastingType SpellItem::GetCastingType() const
{
    return static_cast<MagicSystem::CastingType>(castingType);
}

MagicSystem::SpellType SpellItem::GetSpellType() const
{
    return static_cast<MagicSystem::SpellType>(spellType);
}
