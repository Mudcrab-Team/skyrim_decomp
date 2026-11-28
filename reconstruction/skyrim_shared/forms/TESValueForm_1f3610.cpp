// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1f3610 TESValueForm::sub_1401A1590
#include "TESValueForm_1f3610.h"

// Update the gold value and mark the owning form changed when dynamically castable to TESForm.
void TESValueForm::sub_1401A1590(std::int32_t a_value)
{
    value = a_value;
    TESForm1f3610* form = dynamic_cast<TESForm1f3610*>(this);
    if (form) {
        form->AddChange(2);
    }
}
