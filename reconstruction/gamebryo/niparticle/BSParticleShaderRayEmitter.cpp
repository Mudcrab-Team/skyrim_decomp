// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSParticleShaderRayEmitter","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSParticleShaderRayEmitter: EXE_RTTI
// Slot6: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x15362a0 BSParticleShaderRayEmitter::Slot6
// 0x1536280 BSParticleShaderRayEmitter::HasMember
// HasMember: GUESS(low)
#include "BSParticleShaderRayEmitter.h"
// Slot6: GUESS(low); method name inferred from vtable owner and slot
void* BSParticleShaderRayEmitter::Slot6() const
{
    return member;
}


int BSParticleShaderRayEmitter::HasMember() const
{
    return member != nullptr;
}
