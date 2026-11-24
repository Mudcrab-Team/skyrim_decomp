// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x1dcb30 ReconstructedTESActorBaseData::TESActorBaseData::Function1dcb30
// 0x1dcb50 ReconstructedTESActorBaseData::TESActorBaseData::Function1dcb50
// 0x1dd980 ReconstructedTESActorBaseData::TESActorBaseData::Function1dd980
#include "TESActorBaseData_1dcb30.h"



namespace ReconstructedTESActorBaseData {

// Replace the template-form pointer.
void TESActorBaseData::Function1dcb30(void* a_template)
{
    baseTemplateForm = a_template;
}

// Replace the template-use mask.
void TESActorBaseData::Function1dcb50(std::uint16_t a_flags)
{
    actorData.templateUseFlags = a_flags;
}

// Replace the voice type.
void TESActorBaseData::Function1dd980(BGSVoiceType* a_voice)
{
    voiceType = a_voice;
}

}
