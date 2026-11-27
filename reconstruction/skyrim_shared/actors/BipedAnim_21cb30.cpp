// Source exposure: mixed (pinned image, cited public declarations, the 2013 map and the FNV sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build; names as labelled in the header.
// Adapted bodies: none
// 0x21cb30 BipedAnim::IsFaceGenObject
#include "BipedAnim_21cb30.h"

// Guess: true when the slot's model part has its face-generation flag set.
bool BipedAnim::IsFaceGenObject(BIPED_OBJECT a_slot)
{
    const TESModel* part = objects[a_slot].part;
    return part && (part->flags & TESModel::kFaceGenModel);
}
