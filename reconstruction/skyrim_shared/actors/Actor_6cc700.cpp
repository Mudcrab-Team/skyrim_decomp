// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6cc700 Actor::GetCurrentAmmo
// Adapted bodies: none
#include "Actor_6cc700.h"

TESAmmo* Actor::GetCurrentAmmo() const
{
    InventoryEntryData* entry = GetCurrentAmmoEntry();
    TESForm* form = entry ? entry->GetObject() : nullptr;
    if (form && form->IsAmmo()) {
        return static_cast<TESAmmo*>(form);
    }
    return nullptr;
}
