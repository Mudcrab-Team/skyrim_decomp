// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraSayToTopicInfo: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x186fb0 ExtraSayToTopicInfo::GetType
// Code origin: written for this reconstruction from the listing; names from the public address library.
// SPDX-License-Identifier: CC0-1.0
// 0x186f70 ExtraSayToTopicInfo::Function186f70
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "ExtraSayToTopicInfo.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraSayToTopicInfo::GetType() const
{
    return 0x71;
}

void SayToTopicInfoTailTarget_1405ECE60(void* value, ExtraSayToTopicInfo* self);

void ExtraSayToTopicInfo::Function186f70(void* value)
{
    ptr38 = value;
    return SayToTopicInfoTailTarget_1405ECE60(value, this);
}
