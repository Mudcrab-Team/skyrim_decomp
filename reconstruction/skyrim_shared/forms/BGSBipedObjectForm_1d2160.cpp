// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x1d2160 ReconstructedBGSBipedObjectForm::BGSBipedObjectForm::Function1d2160
#include "BGSBipedObjectForm_1d2160.h"



namespace ReconstructedBGSBipedObjectForm {

// Test whether the two slot masks overlap.
bool BGSBipedObjectForm::Function1d2160(const BGSBipedObjectForm* a_other) const
{
    return (unk08 & a_other->unk08) != 0;
}

}
