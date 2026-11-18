// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1df4c0 TESBipedModelForm::CopyComponent
#include "TESBipedModelForm.h"
void TESBipedModelForm::CopyComponent(BaseFormComponent* rhs) { auto* other=dynamic_cast<TESBipedModelForm*>(rhs); if(other) { worldModels[0].CopyComponent(&other->worldModels[0]); worldModels[1].CopyComponent(&other->worldModels[1]); inventoryIcons[0].CopyComponent(&other->inventoryIcons[0]); messageIcons[0].CopyComponent(&other->messageIcons[0]); inventoryIcons[1].CopyComponent(&other->inventoryIcons[1]); messageIcons[1].CopyComponent(&other->messageIcons[1]); constraintTemplate.CopyComponent(&other->constraintTemplate); } }

