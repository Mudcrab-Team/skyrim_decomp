// Source exposure: mixed (local binary analysis and public names).
// 0x5569a0 compared function
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"SimpleAnimationGraphManagerLoadingTask","rationale":"vtable owner and slot; method spelling invented","slot":19},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SimpleAnimationGraphManagerLoadingTask: EXE_RTTI
// Slot19: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Function5569a0, ManagerStub, its slots: GUESS(low)
#pragma once
#include <cstdint>
// Slot19: GUESS(low); method name inferred from vtable owner and slot
class SimpleAnimationGraphManagerLoadingTask
{
public:
    virtual void* Slot19() const;
    void Function5569a0();  // compared: 0x5569a0
    std::uint8_t padding[0x2c8];
    void* member;
};
