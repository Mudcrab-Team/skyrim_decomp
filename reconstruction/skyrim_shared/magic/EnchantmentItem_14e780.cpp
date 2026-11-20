// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x14e760 Leaf14e760::Invoke
// 0x14e790 Leaf14e790::Invoke
// 0x14e780 EnchantmentItem::GetData1
#include "EnchantmentItem_14e780.h"

// RVA 0x14e760, 6 bytes: returns the chunk tag 'ENIT'.
std::uint32_t EnchantmentItem::GetChunkID()
{
    return 0x54494E45;
}

// RVA 0x14e790, 6 bytes: returns 0x30.
std::uint32_t EnchantmentItem::GetDataSize() const
{
    return 0x30;
}

// RVA 0x14e780, 8 bytes: the data block starts at +0x90.
const MagicItem::Data* EnchantmentItem::GetData1() const
{
    return reinterpret_cast<const MagicItem::Data*>(unknown90);
}
