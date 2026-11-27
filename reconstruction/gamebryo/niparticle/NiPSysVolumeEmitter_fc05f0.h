// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original constructor using the observed base-constructor boundary.
// SPDX-License-Identifier: CC0-1.0
// NiPSysVolumeEmitter, CtorBasefc05f0: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <cfloat>

class CtorBasefc05f0
{
public:
    CtorBasefc05f0();
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    std::uint8_t unknown08[104];
};
static_assert(sizeof(CtorBasefc05f0) == 112, "base extent");

class NiPSysVolumeEmitter : public CtorBasefc05f0
{
public:
    NiPSysVolumeEmitter();
    void Unk_00() override;
    void Unk_02() override;
    void Unk_18() override;
    void Unk_19() override;
    void Unk_1A() override;
    void Unk_1B() override;
    void Unk_1C() override;
    void Unk_1D() override;
    void Unk_2B() override;
    virtual void Unk_2C();
    virtual void Unk_2D();
    void* volume;
};
static_assert(offsetof(NiPSysVolumeEmitter, volume) == 112, "member position");
