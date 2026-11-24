// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xa00860 Actor::GetEquippedSpell
// Adapted bodies: none
#include "Actor_a00860.h"

SpellItem* Actor::GetEquippedSpell(IVirtualMachine* a_vm, std::uint32_t a_stackID, Actor* a_actor, std::int32_t a_slot)
{
    SpellItem* result;
    if (static_cast<std::uint32_t>(a_slot) < 4) {
        MagicItem* form = a_actor->selectedSpells[a_slot];
        if (form) {
            if (form->formType == 0x16) {
                result = static_cast<SpellItem*>(form);
            } else {
                return nullptr;
            }
        } else if (a_slot == 2) {
            return a_actor->Function6d7090();
        } else {
            result = nullptr;
        }
    } else {
        a_vm->TraceStack(g_msga00860, a_stackID, 2);
        result = nullptr;
    }
    return result;
}
