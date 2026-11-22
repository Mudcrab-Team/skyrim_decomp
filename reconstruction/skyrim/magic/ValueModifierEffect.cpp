// Source exposure: mixed (pinned image listing, labelled declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation.
// Adapted bodies: SetActorValue follows the cited Fallout 4 sibling (author-permission).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/fallout/magic/valuemodifiereffect.h:24
// 0x5ba090 ValueModifierEffect::SetActorValue
// 0x5bcba0 ValueModifierEffect::Function5bcba0
// 0x5bb320 ValueModifierEffect::Function5bb320
// 0x5bb990 ValueModifierEffect::Function5bb990
// ActiveEffect::source, ActiveEffect::flags, ActiveEffect::Flag::kEnchanting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kModeFlag04, kModeFlag10: OBSERVED
// ValueModifierEffect::SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
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

namespace {
constexpr std::uint32_t kEnchanting = 1u << 8;
constexpr std::uint32_t kModeFlag04 = 1u << 2;
constexpr std::uint32_t kModeFlag10 = 1u << 4;
}

// Store the source object and its enchanting flag.
void ValueModifierEffect::Function5bb320(TESBoundObject* a_source, bool a_enchanting)
{
    source = a_source;
    flags = a_enchanting ? (flags | kEnchanting) : (flags & ~kEnchanting);
}

// Set both mode flags for this effect.
void ValueModifierEffect::Function5bb990(bool a_enabled)
{
    auto updated = a_enabled ? (flags | kModeFlag04) : (flags & ~kModeFlag04);
    updated = a_enabled ? (updated | kModeFlag10) : (updated & ~kModeFlag10);
    flags = updated;
}
