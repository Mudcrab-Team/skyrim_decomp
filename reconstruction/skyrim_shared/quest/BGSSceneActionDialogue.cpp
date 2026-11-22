// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of Function3ab500.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x3ab520 BGSSceneActionDialogue::GetType
// 0x3ab280 BGSSceneActionDialogue::GetEmotionType
// 0x3ab290 BGSSceneActionDialogue::GetEmotionValue
// 0x3ab530 BGSSceneActionDialogue::Loops
// 0x3ab2a0 BGSSceneActionDialogue::FacesTarget
// 0x3abcf0 BGSSceneActionDialogue::Unk_0B
// 0x3ab1c0 BGSSceneActionDialogue::~BGSSceneActionDialogue
// 0x3ab500 BGSSceneActionDialogue::Function3ab500
#include "BGSSceneActionDialogue.h"

template <class T>
static T& RawAt(const void* a_base, std::ptrdiff_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_base)) + a_offset);
}

BGSSceneActionDialogue::BGSSceneActionDialogue()
{
}

BGSSceneActionDialogue::Type BGSSceneActionDialogue::GetType() const
{
    return static_cast<Type>(0);
}

EmotionType BGSSceneActionDialogue::GetEmotionType() const
{
    return static_cast<EmotionType>(RawAt<std::uint32_t>(this, 0x38));
}

std::uint32_t BGSSceneActionDialogue::GetEmotionValue() const
{
    return RawAt<std::uint32_t>(this, 0x3c);
}

bool BGSSceneActionDialogue::Loops() const
{
    return RawAt<std::uint8_t>(this, 0x12) & 1;
}

bool BGSSceneActionDialogue::FacesTarget() const
{
    return (flags10 >> 0xF) & 1;
}

void BGSSceneActionDialogue::Unk_0B()
{
    flags10 &= 0xFFFFBFFF;
    RawAt<std::uint32_t>(this, 0x34) = 0;
    BGSSceneActionBase::Unk_0B();
}

void BGSSceneActionDialogue::Function3ab500()
{
    if (topic) {
        topic->Slot23(true);
    }
}
