// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: shaped like TestBit in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Cookbook: 0x258470 16
// SPDX-License-Identifier: CC0-1.0
// 0x258470 Obj258470::ValidateForm
#include "Obj258470.h"

namespace
{
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
bool TestBit(std::uint32_t value, std::uint32_t bit)
{
    return ((value >> bit) & 1) != 0;
}
}  // namespace

// Validate a form for region placement and return an error code or zero.
std::uint32_t Obj258470::ValidateForm(BaseForm258470* form)
{
    if (!form)
    {
        return 1;
    }
    if (TestBit(form->flags, 5))
    {
        return 2;
    }
    if (form->formType == 0x14)
    {
        return 0;
    }
    if (dynamic_cast<BoundObject258470*>(form) == nullptr)
    {
        return 5;
    }

    ModelForm258470* modelForm = dynamic_cast<ModelForm258470*>(form);
    if (!modelForm && form->formType != 0x0F)
    {
        return 6;
    }
    if (form->formType != 0x0F && modelForm->modelData.HasModel() == 0)
    {
        return 7;
    }
    return 0;
}
