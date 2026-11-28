// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x23f9a0 GetArmorInSlotFunctor23f9a0::Visit
// Adapted bodies: none
#include "GetArmorInSlotFunctor23f9a0.h"

// Record the armor form if it occupies the requested biped slot, stopping once found.
std::uint32_t GetArmorInSlotFunctor23f9a0::Visit(EntryData23f9a0* entry)
{
    BaseForm23f9a0* form = entry->object;
    if (form->formType == 0x1A)
    {
        ArmorForm23f9a0* armor = static_cast<ArmorForm23f9a0*>(form);
        if (armor->bipedModel.HasSlot(slotIndex))
        {
            foundArmor = form;
        }
    }
    return foundArmor == nullptr ? 1u : 0u;
}
