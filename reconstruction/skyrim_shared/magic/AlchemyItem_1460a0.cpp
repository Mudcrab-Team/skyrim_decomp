// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AlchemyItem, data, costOverride, flags, addictionItem, addictionChance, consumptionSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMagicItemData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x1460a0 AlchemyItem::CopyMagicItemData
#include "AlchemyItem_1460a0.h"

#include <cstring>

// Copy alchemy data only from a non-null item of the same form type.
void AlchemyItem::CopyMagicItemData(MagicItem* source)
{
    if (source && source->formType == formType)
    {
        const AlchemyItem* item = static_cast<AlchemyItem*>(source);
        data.costOverride = item->data.costOverride;
        data.flags = item->data.flags;
        data.addictionItem = item->data.addictionItem;
        std::memcpy(&data.addictionChance, &item->data.addictionChance, sizeof(data.addictionChance));
        data.consumptionSound = item->data.consumptionSound;
    }
}
