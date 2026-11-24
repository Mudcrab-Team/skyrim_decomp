// Source exposure: mixed (local instruction listing of the pinned image and community declarations).
// 0x1ef9c0 TESReactionForm::InitializeDataComponent
// Code origin: original from the listing and community declarations, except ~TESReactionForm, which is close to the sibling bodies named below
// SPDX-License-Identifier: CC0-1.0
// 0x1f0370 TESReactionForm::Function1f0370
// 0x1f08c0 TESReactionForm::~TESReactionForm
// Adapted bodies: ~TESReactionForm only; the FNV body named by the Sibling source line below.
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/fallout_shared/tesreactionform.cpp
// TESReactionForm: SIBLING(momusdigital/fnv_decomp@91e1b6e, no-licence)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESReactionForm.cpp:22 (~TESReactionForm is close to it, similarity 0.75 by tools/check_origin.py)
// TESReactionForm::~TESReactionForm: SIBLING(fo4-private@1b765c70, author-permission)
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

// BaseFormComponent::~BaseFormComponent: GUESS(low); empty body, inlined by the compared destructor.
BaseFormComponent::~BaseFormComponent()
{
}

// Not compared: defined so the compiler emits the vftable and, beside it, the deleting destructor.
TESReactionForm::TESReactionForm()
{
}

TESReactionForm::~TESReactionForm()
{
    ClearDataComponent();
}
