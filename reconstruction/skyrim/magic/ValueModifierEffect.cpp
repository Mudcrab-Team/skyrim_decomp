// Source exposure: mixed (pinned image listing and authorized sibling hints).
// SPDX-License-Identifier: CC0-1.0
// Code origin: brown-room reconstruction from disassembly
// ValueModifierEffect, SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/fallout/magic/valuemodifiereffect.h:24
// SetExplosionLocation: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x5ba090 ValueModifierEffect::SetActorValue
// 0x5bcba0 ValueModifierEffect::Function5bcba0
// Adapted bodies: SetActorValue follows fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6 (author permission); the same one-line setter is in momusdigital/fnv_decomp@91e1b6e src/fallout/magic/valuemodifiereffect.h:24.
#include "ValueModifierEffect.h"

// EffectControllerStandIn, Slot00-Slot30: GUESS(low) STANDIN
namespace
{
class EffectControllerStandIn
{
public:
    virtual void Slot00();
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
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30(const void* a_location);
};
}

void ValueModifierEffect::SetActorValue(std::uint32_t value) { actorValue = value; }

void ValueModifierEffect::Function5bcba0(const void* a_location)
{
    auto* controller = reinterpret_cast<EffectControllerStandIn*>(
        reinterpret_cast<std::uint8_t*>(this) + 8);
    controller->Slot30(a_location);
}
