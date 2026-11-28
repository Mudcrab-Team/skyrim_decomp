// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x82d130 CombatInventoryItemComposite::sub_14077DF10
#include "CombatInventoryItemComposite_82d130.h"
void CombatInventoryItemComposite::sub_14077DF10(char* a_buf, std::uint32_t a_size)
{
    FormatPairDescription(a_buf, a_size, gCompositeFormat, primaryItem->GetEditorID(), secondaryItem->GetEditorID());
}
