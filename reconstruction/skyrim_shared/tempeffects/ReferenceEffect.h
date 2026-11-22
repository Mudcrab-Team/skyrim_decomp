// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function5d88c0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReferenceEffect, GetAttached, ReferenceEffectController, controller: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Function5d88c0, unknown08: GUESS(low)
// ReferenceEffect::CheckAge, finished, lifetime, age: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>

class ReferenceEffectController
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
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual bool Slot16();
};

class ReferenceEffect
{
public:
    virtual std::uint8_t GetAttached() const;
    bool Function5d88c0();

    bool CheckAge() const;

    std::uint8_t unknown08[8];
    float lifetime;
    std::uint8_t unknown14[12];
    float age;
    std::uint8_t unknown24[12];
    ReferenceEffectController* controller;
    std::uint8_t unknown38[8];
    bool finished;
};
