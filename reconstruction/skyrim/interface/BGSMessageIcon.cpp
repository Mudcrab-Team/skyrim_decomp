// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1d9350 BGSMessageIcon::~BGSMessageIcon
// 0x1d9250 BGSMessageIcon::CopyComponent
#include "BGSMessageIcon.h"
BGSMessageIcon::BGSMessageIcon() {}
BGSMessageIcon::~BGSMessageIcon() { icon.ClearDataComponent(); }
void BGSMessageIcon::CopyComponent(BaseFormComponent* rhs) { auto* other=dynamic_cast<BGSMessageIcon*>(rhs); if(other) { const char* name=other->icon.textureName.value; MemoryScope scope; icon.textureName=name; } }

