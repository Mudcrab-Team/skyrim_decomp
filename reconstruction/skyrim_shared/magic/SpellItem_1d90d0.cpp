// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1d90d0 SpellItem::GetMenuDisplayObject
// Adapted bodies: none
#include "SpellItem_1d90d0.h"

BGSMenuDisplayObject* SpellItem::GetMenuDisplayObject(TESBoundObject* a_form)
{
    if (a_form) {
        if (a_form->formType == FormType::MagicEffect || a_form->formType == FormType::Shout) {
            return &a_form->menuDisplay30;
        }
        if (a_form->Function1e71b0()) {
            return &a_form->menuDisplayA0;
        }
    }
    return nullptr;
}
