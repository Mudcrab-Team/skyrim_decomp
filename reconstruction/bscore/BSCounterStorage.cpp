// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSCounterStorage: EXE_RTTI
// ReadFile: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0xec18e0 BSCounterStorage::ReadFile
// Code origin: written for this reconstruction from the listing; names from the header.
// SPDX-License-Identifier: CC0-1.0
// 0xec18f0 BSCounterStorage::Functionec18f0
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BSCounterStorage.h"
// ReadFile: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BSCounterStorage::ReadFile() const
{
    return 0x2;
}

std::uint32_t BSCounterStorage::Functionec18f0(std::uint32_t delta)
{
    count_24 += delta;
    if (!(count_24 < limit_20))
        limit_20 = count_24 + 1;
    return 0;
}
