// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of Function3ab500. Stamped as a twin of matched 0x3ab280 (skyrim_shared/quest/BGSSceneActionDialogue): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xb78390 Ownerb78390::GetEmotionType
#include "Ownerb78390.h"

template <class T>
static T& RawAt(const void* a_base, std::ptrdiff_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_base)) + a_offset);
}

Ownerb78390::Ownerb78390()
{
}

// guess: same compiled code as matched 0x3ab280 apart from relocated fields; its role here is not established.
EmotionType Ownerb78390::GetEmotionType() const
{
    return static_cast<EmotionType>(RawAt<std::uint32_t>(this, 0x38));
}
