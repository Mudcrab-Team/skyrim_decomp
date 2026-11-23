// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x756cb0 PlayerCharacter::Function756cb0
// Adapted bodies: none
#include "PlayerCharacter_756cb0.h"

const std::uint32_t& PlayerCharacter::GetSlotHandle() const
{
    if (unk8A0 < 15) {
        std::ptrdiff_t i = unk8A0;
        return reinterpret_cast<const std::uint32_t*>(this)[i * 3 + 0x1FC];
    }
    return kNullHandle;
}

std::uint32_t* PlayerCharacter::Function756cb0(std::uint32_t* out)
{
    *out = GetSlotHandle();
    return out;
}
