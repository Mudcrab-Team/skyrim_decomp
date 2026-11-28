// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x14d060 EffectSettingCollection14d060::GetEffectSetting
// Adapted bodies: none
#include "EffectSettingCollection14d060.h"

#include <cstring>

// PDB: the CrashLogger PDB names this EffectSettingCollection::GetEffectSetting; EffectSettingCollection14d060 is a stand-in for EffectSettingCollection with a partial layout.
// Searches the global effect list until null node or null item for a matching editor ID.
EffectItem14d060* EffectSettingCollection14d060::GetEffectSetting(const char* editorID)
{
    for (ListNode14d060* node = &gEffectList14d060; node != nullptr && node->item != nullptr; node = node->next)
    {
        EffectItem14d060* item = node->item;
        if (std::strcmp(item->GetEditorID(), editorID) == 0)
        {
            return item;
        }
    }
    return nullptr;
}
