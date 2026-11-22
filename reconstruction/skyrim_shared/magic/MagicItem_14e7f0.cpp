// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14e7f0 MagicItem::IsValidEnchantmentForWeapon
// Adapted bodies: none
#include "MagicItem_14e7f0.h"

bool MagicItem::IsValidEnchantmentForWeapon() const
{
    return GetCastingType() == MagicSystem::CastingType::kFireAndForget &&
           GetDelivery() == MagicSystem::Delivery::kTouch;
}
