// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0x147790 GameSettingCollection::vfunc_2
#include "GameSettingCollection_147790.h"

// Removes a setting from the collection map by its name key.
void GameSettingCollection::vfunc_2(Setting* a_setting)
{
    if (a_setting && a_setting->name)
    {
        settings.RemoveAt(a_setting->name);
    }
}
