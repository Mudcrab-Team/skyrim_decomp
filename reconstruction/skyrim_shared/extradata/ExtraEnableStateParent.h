// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraEnableStateParent: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// IsNotEqual, flags, parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// parent: GUESS(low); the reference handle is kept as its 32-bit value
#pragma once
#include <cstdint>
#include "BSExtraData.h"

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraEnableStateParent : public BSExtraData
{
public:
    bool IsNotEqual(const BSExtraData* a_rhs) const override;
    virtual std::uint32_t GetType() const;

    std::uint8_t flags;    // 10
    std::uint8_t pad11;    // 11
    std::uint16_t pad12;   // 12
    std::uint32_t parent;  // 14
};
