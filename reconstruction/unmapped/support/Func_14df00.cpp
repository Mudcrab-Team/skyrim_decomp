// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Cookbook: 0x14df00 6
// 0x14df00 Func_14df00::CanApply
// Adapted bodies: none
#include "Func_14df00.h"

// Checks whether effect is compatible with form and actor based on form type and delivery mode.
bool Func_14df00::CanApply(FormBase14df00* form, void* actor, Effect14df00* effect)
{
    bool result = true;
    if (form && effect && dynamic_cast<FormDerived14df00*>(form) != nullptr)
    {
        switch (static_cast<std::uint32_t>(form->formType))
        {
        case 0x1A:
            result = (effect->delivery == 0)
                && (g_effectTable14df00[effect->archetype].kind != 0x2B)
                && ((effect->flags68 & 0x600u) == 0)
                && (!actor || !CheckActor14df00(actor));
            break;
        case 0x29:
            result = (form->byte19D == 8 || effect->delivery == 1)
                && (!actor || !CheckActor14df00(actor));
            break;
        case 0x2A:
            result = (effect->delivery == 1)
                && (!actor || !CheckActor14df00(actor));
            break;
        default:
            break;
        }
    }
    return result;
}
