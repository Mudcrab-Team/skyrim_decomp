// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations.
// 0x1f08c0 TESReactionForm::~TESReactionForm
// Adapted bodies: the FNV body named by the Sibling source line above.
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/fallout_shared/tesreactionform.cpp
// TESReactionForm: SIBLING(momusdigital/fnv_decomp@91e1b6e, no-licence)
#include "TESReactionForm.h"

void TESReactionForm::InitializeDataComponent()
{
    groupFormType = 11;
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
