// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// GrenadeProjectile: EXE_RTTI
// IsGrenadeProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
// IsGrenadeProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSDecalGroup;

// GrenadeProjectile::TargetsWholeBody, GrenadeProjectile::GetDecalGroup, GrenadeProjectile::OnTriggerEnter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x7ec880, 0x7ec890, 0x7ec8c0
// flags1D4: GUESS(low); the dword at offset 0x1D4 from the listing
// decalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the pointer at offset 0x1E0 from the listing
class GrenadeProjectile
{
public:
    virtual std::uint8_t IsGrenadeProjectile() const;
    virtual bool TargetsWholeBody();  // compared: 0x7ec880
    virtual BGSDecalGroup* GetDecalGroup() const;  // compared: 0x7ec890
    virtual void OnTriggerEnter();  // compared: 0x7ec8c0

    std::uint8_t  unk08[0x1CC];  // 08
    std::uint32_t flags1D4;      // 1D4
    std::uint8_t  unk1D8[0x8];   // 1D8
    BGSDecalGroup* decalGroup;   // 1E0
};
static_assert(offsetof(GrenadeProjectile, flags1D4) == 0x1D4, "GrenadeProjectile::flags1D4 offset");
static_assert(offsetof(GrenadeProjectile, decalGroup) == 0x1E0, "GrenadeProjectile::decalGroup offset");
