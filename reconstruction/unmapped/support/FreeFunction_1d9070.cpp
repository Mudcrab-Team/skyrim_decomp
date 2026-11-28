// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1d9070 GetComponentResult1d9070
// Adapted bodies: none
#include "FreeFunction_1d9070.h"

// Queries the component interface from supported form subtypes and returns its slot 4 value.
void* GetComponentResult1d9070(FormBase1d9070* a_form)
{
    if (!a_form) {
        return nullptr;
    }

    Component1d9070* component = nullptr;
    if (a_form->formType == 0x12 || a_form->formType == 0x77) {
        component = static_cast<DerivedFormA1d9070*>(a_form);
    } else if (HasExtendedComponent1d9070(a_form)) {
        component = &static_cast<DerivedFormB1d9070*>(a_form)->component;
    }

    if (!component) {
        return nullptr;
    }
    return component->QueryValue();
}
