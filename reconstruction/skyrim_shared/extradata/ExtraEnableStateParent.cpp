// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the pinned image listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x182a00 ExtraEnableStateParent::Function182a00
// ExtraEnableStateParent::Function182a00: GUESS(low)
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ExtraEnableStateParent: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "ExtraEnableStateParent.h"

bool ExtraEnableStateParent::Function182a00(const ExtraEnableStateParent* a_other) const
{
    if (a_other->value14 != value14)
    {
        return true;
    }
    if (a_other->flag10 != flag10)
    {
        return true;
    }
    return false;
}
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraEnableStateParent::GetType() const
{
    return 0x36;
}
