// Source exposure: mixed (local binary analysis and public names).
// 0x4e0f40 compared function
// 0x4e0ee0 compared function
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PathingDoor","rationale":"vtable owner and slot; method spelling invented","slot":2},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PathingDoor: EXE_RTTI
// Slot2: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// PathingDoorTarget, its slots: GUESS(low); stand-in receiver of the compared tail call
#pragma once
#include <cstdint>
// Slot2: GUESS(low); method name inferred from vtable owner and slot
class PathingDoorTarget
{
public:
    virtual ~PathingDoorTarget() = default;
    // Slot01 through Slot10: GUESS(low); placeholders so SetValue lands on slot 11
    virtual void Slot01(std::uint32_t* a_value);
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void SetValue(std::uint32_t a_value);
};

class PathingDoor
{
public:
    virtual std::uint32_t Slot2() const;
    void Function4e0ee0(PathingDoorTarget* a_target);  // compared: 0x4e0ee0
    void Function4e0f40(PathingDoorTarget* a_target);  // compared: 0x4e0f40
    std::uint8_t padding[0x8];
    std::uint32_t member;
};
