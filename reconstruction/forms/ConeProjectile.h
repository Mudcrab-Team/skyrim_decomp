// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"ConeProjectile","rationale":"vtable owner and slot; method spelling invented","slot":194},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// ConeProjectile: EXE_RTTI
// Slot194: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot194: GUESS(low); method name inferred from vtable owner and slot
class ConeProjectile
{
public:
    virtual std::uint8_t Slot194() const;
    // GetKillOnCollision: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the sheet's declaration, without a base class declared here, so no override
    virtual bool GetKillOnCollision();
};
