// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSFaceGenKeyframeMultiple: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSFaceGenKeyframe: STANDIN EXE_RTTI
// BSFaceGenKeyframeMultiple::GetCustomName, BSFaceGenKeyframeMultiple::GetExpressionName, BSFaceGenKeyframeMultiple::GetPhonemeName: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSFaceGenKeyframeMultiple::Unk_0E, BSFaceGenKeyframeMultiple::Unk_0B, BSFaceGenKeyframeMultiple::Unk_09, BSFaceGenKeyframeMultiple::Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFaceGenKeyframe::~BSFaceGenKeyframe, unknown08: GUESS(low)
// values, count, isUpdated, pad1D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_01 to Unk_07, Unk_0A, Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); void placeholders that keep the image's vtable index of the call at 0x70
// Unk_0D: GUESS(low); a void placeholder at vtable index 0x0D
// g_customNameTable, g_expressionNameTable, g_phonemeNameTable: GUESS(low); the image's name tables at 0x20b0828, 0x20b0830 and 0x20b0950
#pragma once

#include <cstdint>
#include <cstddef>

class BSFaceGenKeyframe
{
public:
    virtual ~BSFaceGenKeyframe() = default;
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(BSFaceGenKeyframe) == 0x10, "BSFaceGenKeyframe size");

// The image's tables of name pointers, indexed by the functions below.
extern const char* const g_customNameTable[];
extern const char* const g_expressionNameTable[];
extern const char* const g_phonemeNameTable[];

class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
public:
    static const char* GetCustomName(std::int32_t a_index);  // compared: 0x43ad00; no this pointer, the index arrives in ECX
    static const char* GetExpressionName(std::uint32_t a_index);  // compared: 0x43aca0
    static const char* GetPhonemeName(std::uint32_t a_index);  // compared: 0x43ace0
    virtual void Unk_01();  // 08
    virtual void Unk_02();  // 10
    virtual void Unk_03();  // 18
    virtual void Unk_04();  // 20
    virtual void Unk_05();  // 28
    virtual void Unk_06();  // 30
    virtual void Unk_07();  // 38
    virtual void Unk_0A();  // 50
    virtual std::uint8_t Unk_0C() const;
    virtual void Unk_0D();  // 68
    virtual float Unk_08();  // compared: 0x431d20
    virtual bool Unk_09();  // compared: 0x431da0
    virtual bool Unk_0B();  // compared: 0x432030
    virtual bool Unk_0E(std::uint32_t a_index);  // compared: 0x432080

    float*        values;     // 10
    std::uint32_t count;      // 18
    bool          isUpdated;  // 1C
    std::uint8_t  pad1D[3];   // 1D
};
static_assert(sizeof(BSFaceGenKeyframeMultiple) == 0x20, "BSFaceGenKeyframeMultiple size");
