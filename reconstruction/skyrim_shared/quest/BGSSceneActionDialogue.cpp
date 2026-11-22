// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x3ab500 BGSSceneActionDialogue::Function3ab500
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "BGSSceneActionDialogue.h"

template <class T>
static T& RawAt(const void* a_base, std::ptrdiff_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_base)) + a_offset);
}

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared.
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
    if (target != nullptr) {
        target->TargetMethod(true);
    }
}
