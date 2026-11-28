// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// TestBit2e5620, BaseForm2e5620, Obj2e5620, Obj2e5620::MatchesTarget: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

// TestBit2e5620: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
inline bool TestBit2e5620(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1u) != 0;
}

class BaseForm2e5620
{
public:
    virtual ~BaseForm2e5620();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot0A();
    virtual void Slot0B(); virtual void Slot0C(); virtual void Slot0D(); virtual void Slot0E(); virtual void Slot0F();
    virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14();
    virtual void Slot15(); virtual void Slot16(); virtual void Slot17(); virtual void Slot18(); virtual void Slot19();
    virtual void Slot1A(); virtual void Slot1B(); virtual void Slot1C(); virtual void Slot1D(); virtual void Slot1E();
    virtual void Slot1F(); virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23();
    virtual void Slot24(); virtual void Slot25(); virtual void Slot26(); virtual void Slot27(); virtual void Slot28();
    virtual void Slot29(); virtual void Slot2A(); virtual void Slot2B(); virtual void Slot2C(); virtual void Slot2D();
    virtual void Slot2E(); virtual void Slot2F(); virtual void Slot30(); virtual void Slot31(); virtual void Slot32();
    virtual void Slot33(); virtual void Slot34(); virtual void Slot35(); virtual void Slot36(); virtual void Slot37();
    virtual void Slot38(); virtual void Slot39(); virtual void Slot3A(); virtual void Slot3B(); virtual void Slot3C();
    virtual void* GetSlot3D() const;

    std::uint64_t unk08[2];   // 0x08
    std::uint16_t unk18;      // 0x18
    std::uint8_t m_formType;  // 0x1A
};
static_assert(offsetof(BaseForm2e5620, m_formType) == 0x1A, "m_formType offset");

class Obj2e5620
{
public:
    static bool MatchesTarget(const Obj2e5620* a_obj, const void* a_expected);

    std::uint64_t unk00[2];    // 0x00
    std::uint32_t m_flags;     // 0x10
    std::uint32_t unk14;       // 0x14
    std::uint64_t unk18[5];    // 0x18
    BaseForm2e5620* m_base;    // 0x40
    std::uint64_t unk48[3];    // 0x48
    const void* m_target;      // 0x60
};
static_assert(offsetof(Obj2e5620, m_flags) == 0x10, "m_flags offset");
static_assert(offsetof(Obj2e5620, m_base) == 0x40, "m_base offset");
static_assert(offsetof(Obj2e5620, m_target) == 0x60, "m_target offset");
