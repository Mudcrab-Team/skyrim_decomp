// Source exposure: mixed (pinned image and the cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layout based on the pinned dispatch slots and the cited ActorState declaration.
// ActorState, DoGetMovementSpeed, DoGetRotationSpeed, Unk_14, Unk_15 names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_14 and Unk_15 signatures, FunctionSlot declarations, Function declarations, stateWord, weaponStateWord: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class ActorState
{
public:
    virtual ~ActorState();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual float DoGetMovementSpeed();
    virtual float DoGetRotationSpeed();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    virtual void FunctionSlot09();
    virtual void FunctionSlot0A();
    virtual void FunctionSlot0B();
    virtual void FunctionSlot0C();
    virtual void FunctionSlot0D();
    virtual void FunctionSlot0E();
    virtual void FunctionSlot0F();
    virtual void FunctionSlot10();
    virtual void FunctionSlot11();
    virtual void FunctionSlot12();
    virtual void FunctionSlot13();
    virtual bool Unk_14(std::uint32_t state);
    virtual bool Unk_15(bool drawn);

    bool Function6e1490(std::uint16_t flags);
    bool Function6e14b0(std::uint16_t flags);
    bool Function6e14d0(std::uint16_t flags);
    std::uint16_t Function6e14f0() const;
    bool Function6e1530(std::uint16_t flags) const;

private:
    std::uint32_t stateWord;
    std::uint32_t weaponStateWord;
};
static_assert(sizeof(ActorState) == 0x10, "actor state layout");
