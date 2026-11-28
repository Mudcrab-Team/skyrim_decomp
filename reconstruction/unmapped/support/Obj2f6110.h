// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Info2f6110, Target2f6110, Obj2f6110, Obj2f6110::Apply: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Info2f6110
{
    std::uint32_t unk00[61];  // 0x00
    std::uint32_t m_flags;    // 0xF4
};
static_assert(offsetof(Info2f6110, m_flags) == 0xF4, "m_flags offset");

class Target2f6110
{
public:
    virtual ~Target2f6110();
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
    virtual void V41(); virtual void V42(); virtual void V43(); virtual void V44();
    virtual void V45(); virtual void V46(); virtual void V47(); virtual void V48();
    virtual void V49(); virtual void V4A(); virtual void V4B(); virtual void V4C();
    virtual void V4D(); virtual void V4E(); virtual void V4F(); virtual void V50();
    virtual void V51(); virtual void V52(); virtual void V53(); virtual void V54();
    virtual void V55(); virtual void V56(); virtual void V57(); virtual void V58();
    virtual void V59(); virtual void V5A(); virtual void V5B(); virtual void V5C();
    virtual void V5D(); virtual void V5E(); virtual void V5F(); virtual void V60();
    virtual void V61(); virtual void V62(); virtual void V63(); virtual void V64();
    virtual void V65(); virtual void V66(); virtual void V67(); virtual void V68();
    virtual void V69(); virtual void V6A(); virtual void V6B(); virtual void V6C();
    virtual void V6D(); virtual void V6E(); virtual void V6F();
    virtual Info2f6110* GetInfo();
};

class Obj2f6110
{
public:
    std::uint32_t Apply(Target2f6110* a_target) const;

    bool m_clearFlag;  // 0x00
};
