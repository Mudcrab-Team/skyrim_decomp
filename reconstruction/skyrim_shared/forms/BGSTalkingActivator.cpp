// Code origin: InitializeData, Get/SetObjectVoiceType bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x2671e0 BGSTalkingActivator::InitializeData
// 0x267810 BGSTalkingActivator::SetObjectVoiceType
// 0x2676a0 BGSTalkingActivator::GetObjectVoiceType
#include "BGSTalkingActivator.h"
void BGSTalkingActivator::InitializeData() { voiceType = nullptr; TESObjectACTI::InitializeData(); }
void BGSTalkingActivator::SetObjectVoiceType(BGSVoiceType* a_voice) { voiceType = a_voice; }
BGSVoiceType* BGSTalkingActivator::GetObjectVoiceType() const { return voiceType; }
