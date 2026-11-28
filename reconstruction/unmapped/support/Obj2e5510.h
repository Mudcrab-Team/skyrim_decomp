// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// BaseForm2e5510, Obj2e5510, Obj2e5510::CanProcess, gExcludedA2e5510, gExcludedB2e5510: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BaseForm2e5510
{
public:
    virtual ~BaseForm2e5510();
    virtual void V01(); virtual void V02(); virtual void V03(); virtual void V04();
    virtual void V05(); virtual void V06(); virtual void V07(); virtual void V08();
    virtual void V09(); virtual void V0A(); virtual void V0B(); virtual void V0C();
    virtual void V0D(); virtual void V0E(); virtual void V0F(); virtual void V10();
    virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14();
    virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18();
    virtual void V19(); virtual void V1A(); virtual void V1B(); virtual void V1C();
    virtual void V1D(); virtual void V1E(); virtual void V1F(); virtual void V20();
    virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24();
    virtual void V25(); virtual void V26(); virtual void V27(); virtual void V28();
    virtual void V29(); virtual void V2A(); virtual void V2B(); virtual void V2C();
    virtual void V2D(); virtual void V2E(); virtual void V2F(); virtual void V30();
    virtual void V31(); virtual void V32(); virtual void V33(); virtual void V34();
    virtual void V35(); virtual void V36(); virtual void V37(); virtual void V38();
    virtual void V39(); virtual void V3A(); virtual void V3B(); virtual void V3C();
    virtual void V3D(); virtual void V3E(); virtual void V3F(); virtual void V40();
    virtual void V41();
    virtual bool IsPlayable() const;

    std::uint64_t unk08[2];   // 0x08
    std::uint16_t unk18;      // 0x18
    std::uint8_t m_formType;  // 0x1A
};
static_assert(offsetof(BaseForm2e5510, m_formType) == 0x1A, "m_formType offset");

extern BaseForm2e5510* gExcludedA2e5510;
extern BaseForm2e5510* gExcludedB2e5510;

class Obj2e5510
{
public:
    std::int32_t GetItemCount() const;
    static bool CanProcess(const Obj2e5510* a_ref);

    std::uint64_t unk00[2];   // 0x00
    std::uint32_t m_flags;    // 0x10
    std::uint32_t unk14;      // 0x14
    std::uint64_t unk18[5];   // 0x18
    BaseForm2e5510* m_base;   // 0x40
};
static_assert(offsetof(Obj2e5510, m_flags) == 0x10, "m_flags offset");
static_assert(offsetof(Obj2e5510, m_base) == 0x40, "m_base offset");
