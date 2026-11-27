// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiInterpolator, BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::sub_140D600C0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpolator::Unk_00, NiInterpolator::Unk_01, NiInterpolator::Unk_02, NiInterpolator::Unk_03, NiInterpolator::Unk_04, NiInterpolator::Unk_05, NiInterpolator::Unk_06, NiInterpolator::Unk_07, NiInterpolator::Unk_08, NiInterpolator::Unk_09, NiInterpolator::Unk_0A, NiInterpolator::Unk_0B, NiInterpolator::Unk_0C, NiInterpolator::Unk_0D, NiInterpolator::Unk_0E, NiInterpolator::Unk_0F, NiInterpolator::Unk_10, NiInterpolator::Unk_11, NiInterpolator::Unk_12, NiInterpolator::Unk_13, NiInterpolator::Unk_14, NiInterpolator::Unk_15, NiInterpolator::Unk_16, NiInterpolator::Unk_17, NiInterpolator::Unk_18, NiInterpolator::Unk_19, NiInterpolator::Unk_1A, NiInterpolator::Unk_1B, NiInterpolator::Unk_1C, NiInterpolator::Unk_1D, NiInterpolator::Unk_1E, NiInterpolator::Unk_1F, NiInterpolator::Unk_20, NiInterpolator::Unk_21, NiInterpolator::Unk_22, NiInterpolator::Unk_23, NiInterpolator::Unk_24, NiInterpolator::Unk_25, NiInterpolator::Unk_26, NiInterpolator::Unk_27, NiInterpolator::Unk_28, NiInterpolator::UpdateFloat, BSProceduralLightningController::unk00, BSProceduralLightningController::interp0, BSProceduralLightningController::interp1, BSProceduralLightningController::interp2, BSProceduralLightningController::interp3, BSProceduralLightningController::unk150, BSProceduralLightningController::value0, BSProceduralLightningController::value1, BSProceduralLightningController::value2, BSProceduralLightningController::unk164, BSProceduralLightningController::value3: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiInterpolator
{
public:
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
    virtual bool UpdateFloat(float a_time, void* a_target, float& a_value);
};

class BSProceduralLightningController
{
public:
    void sub_140D600C0(float a_time);

    std::uint8_t unk00[0x130];
    NiInterpolator* interp0;
    NiInterpolator* interp1;
    NiInterpolator* interp2;
    NiInterpolator* interp3;
    std::uint64_t unk150;
    float value0;
    float value1;
    float value2;
    float unk164;
    float value3;
};
static_assert(offsetof(BSProceduralLightningController, interp0) == 0x130, "interp0 offset");
static_assert(offsetof(BSProceduralLightningController, value0) == 0x158, "value0 offset");
static_assert(offsetof(BSProceduralLightningController, value3) == 0x168, "value3 offset");
