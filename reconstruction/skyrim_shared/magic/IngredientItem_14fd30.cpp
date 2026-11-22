// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x14fd30 IngredientItem::GetDelivery
// 0x14fce0 IngredientItem::GetCastingType
// 0x14fcf0 IngredientItem::GetChunkID
#include "IngredientItem_14fd30.h"

MagicSystem::Delivery IngredientItem::GetDelivery() const
{
    return static_cast<MagicSystem::Delivery>(0);
}

MagicSystem::CastingType IngredientItem::GetCastingType() const
{
    return static_cast<MagicSystem::CastingType>(1);
}

std::uint32_t IngredientItem::GetChunkID()
{
    return 0x54494E45;
}
