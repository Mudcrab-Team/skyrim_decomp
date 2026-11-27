// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x184ca0 ReconstructedExtraLastFinishedSequence::ExtraLastFinishedSequence::Function184ca0
#include "ExtraLastFinishedSequence_184ca0.h"



namespace ReconstructedExtraLastFinishedSequence {

// Assign the last finished sequence name.
BSFixedString& ExtraLastFinishedSequence::Function184ca0(const char* a_name)
{
    return lastSequenceName = a_name;
}

}
