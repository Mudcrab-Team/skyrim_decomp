// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Extra2f5950, BaseForm2f5950, Obj2f5950, Obj2f5950::AdjustCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Extra2f5950
{
    std::uint64_t unk00[5];  // 0x00
    std::uint16_t unk28;     // 0x28
    std::int16_t m_count;    // 0x2A
};
static_assert(offsetof(Extra2f5950, m_count) == 0x2A, "m_count offset");

struct BaseForm2f5950
{
    std::uint64_t unk00[3];   // 0x00
    std::uint16_t unk18;      // 0x18
    std::uint8_t m_formType;  // 0x1A
};
static_assert(offsetof(BaseForm2f5950, m_formType) == 0x1A, "m_formType offset");

class Obj2f5950
{
public:
    Obj2f5950* AsActor()
    {
        return m_formType == 0x3E ? this : nullptr;
    }

    void SetFlag(bool a_set);
    void AdjustCount(bool a_inc);

    std::uint64_t unk00[3];    // 0x00
    std::uint16_t unk18;       // 0x18
    std::uint8_t m_formType;   // 0x1A
    std::uint8_t unk1B[5];     // 0x1B
    std::uint64_t unk20[4];    // 0x20
    BaseForm2f5950* m_base;    // 0x40
    std::uint64_t unk48[4];    // 0x48
    Extra2f5950* m_extra;      // 0x68
};
static_assert(offsetof(Obj2f5950, m_formType) == 0x1A, "m_formType offset");
static_assert(offsetof(Obj2f5950, m_base) == 0x40, "m_base offset");
static_assert(offsetof(Obj2f5950, m_extra) == 0x68, "m_extra offset");
