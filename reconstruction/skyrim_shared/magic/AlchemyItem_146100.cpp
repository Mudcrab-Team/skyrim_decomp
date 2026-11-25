// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AlchemyItem, data, costOverride, flags, addictionItem, addictionChance, consumptionSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Endian: SYMBOLS(tesv-2013-map)
// 0x146100 AlchemyItem::Endian
#include "AlchemyItem_146100.h"

#include <cstring>
#include <intrin.h>

// Swap the byte order of serialized alchemy data, including unresolved references.
void AlchemyItem::Endian()
{
    // Byte-order intrinsics express the record's endian conversion directly.
    data.costOverride = _byteswap_ulong(data.costOverride);
    // Byte-order intrinsics express the record's endian conversion directly.
    data.flags = _byteswap_ulong(data.flags);
    // Reference-sized serialized values need byte-order conversion too.
    data.addictionItem = reinterpret_cast<SpellItem*>(_byteswap_uint64(reinterpret_cast<std::uintptr_t>(data.addictionItem)));
    std::uint32_t chance;
    std::memcpy(&chance, &data.addictionChance, sizeof(chance));
    // Swap the floating-point representation without numeric conversion.
    chance = _byteswap_ulong(chance);
    std::memcpy(&data.addictionChance, &chance, sizeof(chance));
    // Reference-sized serialized values need byte-order conversion too.
    data.consumptionSound = reinterpret_cast<BGSSoundDescriptorForm*>(_byteswap_uint64(reinterpret_cast<std::uintptr_t>(data.consumptionSound)));
}
