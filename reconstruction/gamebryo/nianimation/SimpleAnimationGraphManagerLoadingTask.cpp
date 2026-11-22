// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x5569a0 SimpleAnimationGraphManagerLoadingTask::Function5569a0
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"SimpleAnimationGraphManagerLoadingTask","rationale":"vtable owner and slot; method spelling invented","slot":19},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// SimpleAnimationGraphManagerLoadingTask: EXE_RTTI
// Slot19: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "SimpleAnimationGraphManagerLoadingTask.h"

// ManagerStub: GUESS(low); local view of the manager's vtable slot 19.
class ManagerStub
{
public:
    virtual ~ManagerStub() = default;
    // Slot01 through Slot18: GUESS(low); placeholders so Invoke lands on slot 19
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Invoke();
};

void SimpleAnimationGraphManagerLoadingTask::Function5569a0()
{
    reinterpret_cast<ManagerStub*>(member)->Invoke();
}

// Slot19: GUESS(low); method name inferred from vtable owner and slot
void* SimpleAnimationGraphManagerLoadingTask::Slot19() const
{
    return member;
}
