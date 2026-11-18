// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"TESRegionObject","rationale":"vtable owner and slot; method spelling invented","slot":2},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// TESRegionObject: EXE_RTTI
// Slot2: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x258700 TESRegionObject::Slot2
#include "TESRegionObject.h"
// Slot2: GUESS(low); method name inferred from vtable owner and slot
void* TESRegionObject::Slot2() const
{
    return member;
}
