// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1466e0 AlchemyItem::GetDelivery
// 0x146670 Leaf146670::Invoke
// 0x1466d0 Leaf1466d0::Invoke
#include "AlchemyItem_1466e0.h"

// RVA 0x1466e0, 3 bytes: returns delivery 0.
MagicSystem::Delivery AlchemyItem::GetDelivery() const
{
    return static_cast<MagicSystem::Delivery>(0);
}

// RVA 0x146670, 6 bytes: returns casting type 1.
MagicSystem::CastingType AlchemyItem::GetCastingType() const
{
    return static_cast<MagicSystem::CastingType>(1);
}

// RVA 0x1466d0, 6 bytes: returns 0x20.
std::uint32_t AlchemyItem::GetDataSize() const
{
    return 0x20;
}
