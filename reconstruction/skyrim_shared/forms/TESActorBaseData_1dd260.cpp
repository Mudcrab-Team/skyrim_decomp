// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1dd260 TESActorBaseData::Function1dd260
// Adapted bodies: none
#include "TESActorBaseData_1dd260.h"

namespace
{
    // Follows the template chain while it stays on NPCs, intersecting their template-use flags.
    TESForm* WalkTemplates(TESForm* a_form, TemplateFlags* a_flags)
    {
        TESForm* result = nullptr;
        while (a_form) {
            if (a_form->formType != FormType::NPC) {
                result = a_form;
                break;
            }
            TESNPC* npc = static_cast<TESNPC*>(a_form);
            *a_flags &= npc->templateUseFlags.value;
            a_form = npc->baseTemplateForm;
        }
        return result;
    }
}

TESForm* TESActorBaseData::Function1dd260(TESForm* a_form, TemplateFlags* a_flags)
{
    a_flags->value = 0xFFFF;
    return WalkTemplates(a_form, a_flags);
}
