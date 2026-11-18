// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSSceneActionDialogue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSceneActionDialogue::GetEmotionType, BGSSceneActionDialogue::GetEmotionValue, BGSSceneActionDialogue::Loops, BGSSceneActionDialogue::FacesTarget, BGSSceneActionDialogue::Unk_0B, BGSSceneActionDialogue::~BGSSceneActionDialogue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSceneActionBase, BGSSceneActionBase::Unk_0B, BGSSceneActionBase::unknown08, BGSSceneActionBase::unknown14: GUESS(low)
// EmotionType: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

enum class EmotionType : std::uint32_t
{
    kNone = 0,
};

class BGSSceneActionBase
{
public:
    virtual void Unk_0B();  // slot 0

    std::uint8_t unknown08[0x8];  // 08
    std::uint32_t flags10;  // 10
    std::uint8_t unknown14[0x2C];  // 14
};
static_assert(sizeof(BGSSceneActionBase) == 0x40, "BGSSceneActionBase size");

class BGSSceneActionDialogue : public BGSSceneActionBase
{
public:
    BGSSceneActionDialogue();
    // BGSSceneActionDialogue::GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x3ab520; the underlying type is a stand-in of four bytes, and only the zero value is returned
    enum class Type : std::uint32_t {};
    virtual Type GetType() const;  // compared: 0x3ab520
    virtual EmotionType GetEmotionType() const;  // compared: 0x3ab280
    virtual std::uint32_t GetEmotionValue() const;  // compared: 0x3ab290
    virtual bool Loops() const;  // compared: 0x3ab530
    virtual bool FacesTarget() const;  // compared: 0x3ab2a0
    virtual void Unk_0B();  // compared: 0x3abcf0
    virtual ~BGSSceneActionDialogue() {}  // compared: 0x3ab1c0 (scalar deleting destructor)
};
static_assert(sizeof(BGSSceneActionDialogue) == 0x40, "BGSSceneActionDialogue size");
