// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6767e0 Character::GetEditorInteriorCell
// Adapted bodies: none
#include "Character_6767e0.h"

TESObjectCELL* Character::GetEditorInteriorCell()
{
    TESObjectCELL* result = nullptr;
    TESForm* form = editorLocForm;
    if (form && form->formType == kCell) {
        result = static_cast<TESObjectCELL*>(form);
        if (!(result->cellFlags & kIsInteriorCell)) {
            result = nullptr;
        }
    }
    return result;
}
