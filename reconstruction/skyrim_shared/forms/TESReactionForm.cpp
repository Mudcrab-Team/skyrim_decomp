// Source exposure: mixed (local instruction listing of the pinned image and community declarations).
// 0x1ef9c0 TESReactionForm::InitializeDataComponent
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1f0370 TESReactionForm::Function1f0370
// Adapted bodies: none
#include "TESReactionForm.h"

void TESReactionForm::InitializeDataComponent()
{
    groupFormType = 11;
}

std::uint32_t TESReactionForm::Function1f0370(const void* a_faction) const
{
    if (!a_faction) {
        return 0;
    }
    for (const auto* node = &reactions; node && node->item; node = node->next) {
        if (node->item->form == a_faction) {
            return node->item->fightReaction;
        }
    }
    return 0;
}
