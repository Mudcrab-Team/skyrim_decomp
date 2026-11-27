// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x192450 INISettingCollection::WriteAllSettings
#include "INISettingCollection_192450.h"

// Writes every setting in the list when the collection handle is open.
bool INISettingCollection::WriteAllSettings()
{
    bool ok = handle != nullptr;
    if (handle)
    {
        for (SettingNode* node = &settings; node != nullptr; node = node->next)
        {
            ok &= WriteSetting(node->item);
        }
    }
    return ok;
}
