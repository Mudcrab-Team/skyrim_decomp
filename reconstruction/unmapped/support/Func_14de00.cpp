// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Cookbook: 0x14de00 6
// 0x14de00 Func_14de00::CanApplyWrapper
// Adapted bodies: none
#include "Func_14de00.h"

static inline bool CanApplyForm14de00(FormBase14de00* form, void* actor, Effect14de00* effect)
{
    bool result = true;
    if (form && effect && dynamic_cast<FormDerived14de00*>(form) != nullptr)
    {
        switch (static_cast<std::uint32_t>(form->formType))
        {
        case 0x1A:
            result = (effect->delivery == 0)
                && (g_effectTable14de00[effect->archetype].kind != 0x2B)
                && ((effect->flags68 & 0x600u) == 0)
                && (!actor || !CheckActor14de00(actor));
            break;
        case 0x29:
            result = (form->byte19D == 8 || effect->delivery == 1)
                && (!actor || !CheckActor14de00(actor));
            break;
        case 0x2A:
            result = (effect->delivery == 1)
                && (!actor || !CheckActor14de00(actor));
            break;
        default:
            break;
        }
    }
    return result;
}

// Unpacks form and optional actor from wrapper and validates effect compatibility.
bool Func_14de00::CanApplyWrapper(TargetWrapper14de00* wrapper, Effect14de00* effect)
{
    if (!wrapper)
    {
        return false;
    }
    void* actor = wrapper->actorSlot ? *wrapper->actorSlot : nullptr;
    return CanApplyForm14de00(wrapper->form, actor, effect);
}
