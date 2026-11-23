// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1d20f0 Leaf1d20f0::Invoke
// 0x1d20e0 BGSBipedObjectForm::InitializeDataComponent
// 0x1d21f0 BGSBipedObjectForm::~BGSBipedObjectForm
// Code origin: Original reconstruction from the pinned image listing and labelled community declarations; existing bodies retained.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1d2170 BGSBipedObjectForm::FillsBipedSlot
#include "BGSBipedObjectForm.h"

// Test the requested slot in the component's bit mask.
bool BGSBipedObjectForm::FillsBipedSlot(std::int32_t a_slot) const
{
    if (a_slot >= 32) {
        return false;
    }
    return (unk08 & (std::uint32_t{1} << a_slot)) != 0;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSBipedObjectForm::BGSBipedObjectForm()
{
}

// Compared function: RVA 0x1d20f0, 3 bytes, BGSBipedObjectForm::ClearDataComponent.
void BGSBipedObjectForm::ClearDataComponent()
{
}

// Compared function: RVA 0x1d20e0, 8 bytes, BGSBipedObjectForm::InitializeDataComponent.
void BGSBipedObjectForm::InitializeDataComponent()
{
    unk08 = 0;
}

// Compared as the scalar deleting destructor; the sized delete it calls is bound by RVA in
// bind-hints.json.
BGSBipedObjectForm::~BGSBipedObjectForm()
{
}
