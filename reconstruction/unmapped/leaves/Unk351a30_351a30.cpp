// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x351a30 Unk351a30::DispelAllSpells
// Adapted bodies: Unk351a30::DispelAllSpells, from the Fallout: New Vegas decompilation (CC0-1.0), statement order only; no names taken
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:16217
#include "Unk351a30_351a30.h"

// Console handler: dispels every active spell on the calling actor reference.
bool Unk351a30::DispelAllSpells(void* a_params, void* a_scriptData, TESObjectREFR* a_thisObj)
{
    if (a_thisObj) {
        Actor* actor = dynamic_cast<Actor*>(a_thisObj);
        if (actor) {
            actor->MagicTarget::DispelAllSpells(false);
        }
    }
    return true;
}
