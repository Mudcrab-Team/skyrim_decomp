// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x14d510 EffectSettingCollection14d510::InitItems
// Adapted bodies: none
#include "EffectSettingCollection14d510.h"

// PDB: the CrashLogger PDB names this EffectSettingCollection::InitItems; EffectSettingCollection14d510 is a stand-in for EffectSettingCollection with a partial layout.
// Walks the global effect list until null node or null item and invokes InitItem.
void EffectSettingCollection14d510::InitItems()
{
    for (ListNode14d510* node = &gEffectList14d510; node != nullptr && node->item != nullptr; node = node->next)
    {
        node->item->InitItem();
    }
}
