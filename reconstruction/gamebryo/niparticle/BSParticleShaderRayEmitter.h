// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSParticleShaderRayEmitter","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSParticleShaderRayEmitter: EXE_RTTI
// Slot6: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot6: GUESS(low); method name inferred from vtable owner and slot
class BSParticleShaderRayEmitter
{
public:
    virtual void* Slot6() const;
    std::uint8_t padding[0xed8];
    void* member;
};
