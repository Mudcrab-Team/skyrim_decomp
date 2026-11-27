// Source exposure: binary-analysis (local target observations; labelled symbol names).
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// NiBlendInterpolator, NiBlendInterpolator::GuaranteeTimeRange: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpolator, NiInterpolator::GuaranteeTimeRange: STANDIN SYMBOLS(fo4-pdb)
// InterpArrayItem, interpolator, unusedState, baseState, unk18, unk19, unk1A, unk1B, unk1C, unk20, unk28: GUESS(low); local structural names
// NiInterpolator::Unk01, NiInterpolator::Unk02, NiInterpolator::Unk03, NiInterpolator::Unk04, NiInterpolator::Unk05, NiInterpolator::Unk06, NiInterpolator::Unk07, NiInterpolator::Unk08, NiInterpolator::Unk09, NiInterpolator::Unk0A, NiInterpolator::Unk0B, NiInterpolator::Unk0C, NiInterpolator::Unk0D, NiInterpolator::Unk0E, NiInterpolator::Unk0F, NiInterpolator::Unk10, NiInterpolator::Unk11, NiInterpolator::Unk12, NiInterpolator::Unk13, NiInterpolator::Unk14, NiInterpolator::Unk15, NiInterpolator::Unk16, NiInterpolator::Unk17, NiInterpolator::Unk18, NiInterpolator::Unk19, NiInterpolator::Unk1A, NiInterpolator::Unk1B, NiInterpolator::Unk1C, NiInterpolator::Unk1D, NiInterpolator::Unk1E, NiInterpolator::Unk1F, NiInterpolator::Unk20, NiInterpolator::Unk21, NiInterpolator::Unk22, NiInterpolator::Unk23, NiInterpolator::Unk24, NiInterpolator::Unk25, NiInterpolator::Unk26, NiInterpolator::Unk27, NiInterpolator::Unk28, NiInterpolator::Unk29, NiInterpolator::Unk2A, NiInterpolator::Unk2B, NiInterpolator::Unk2C, NiInterpolator::Unk2D, NiInterpolator::Unk2E, NiInterpolator::Unk2F, NiInterpolator::Unk30, NiInterpolator::Unk31, NiInterpolator::Unk32: GUESS(low) STANDIN; unused virtual slots
#pragma once
#include <cstdint>
class NiInterpolator
{
public:
    virtual ~NiInterpolator();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0A();
    virtual void Unk0B();
    virtual void Unk0C();
    virtual void Unk0D();
    virtual void Unk0E();
    virtual void Unk0F();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1A();
    virtual void Unk1B();
    virtual void Unk1C();
    virtual void Unk1D();
    virtual void Unk1E();
    virtual void Unk1F();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2A();
    virtual void Unk2B();
    virtual void Unk2C();
    virtual void Unk2D();
    virtual void Unk2E();
    virtual void Unk2F();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void GuaranteeTimeRange(float start, float end);
    std::uint8_t baseState[0x10];
};
class NiBlendInterpolator : public NiInterpolator
{
public:
    struct InterpArrayItem
    {
        NiInterpolator* interpolator;
        std::uint8_t unusedState[0x18];
    };
    void GuaranteeTimeRange(float start, float end) override;
    std::uint8_t unk18;
    std::uint8_t unk19;
    std::uint8_t unk1A;
    std::uint8_t unk1B;
    float unk1C;
    InterpArrayItem* unk20;
    NiInterpolator* unk28;
};
