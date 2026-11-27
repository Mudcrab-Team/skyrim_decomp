// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x27ed40 ReconstructedTESObjectARMO::TESObjectARMO::Function27ed40
#include "TESObjectARMO_27ed40.h"



namespace ReconstructedTESObjectARMO {

// Forward the slot query to the biped-object component.
bool TESObjectARMO::Function27ed40(std::int32_t a_slot) const
{
    return BGSBipedObjectForm::FillsBipedSlot(a_slot);
}

}
