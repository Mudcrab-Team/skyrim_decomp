// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
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

// DialogueTarget: GUESS(low) STANDIN; virtual slot holder for Function3ab500's tail call.
class DialogueTarget
{
public:
    virtual void PadSlot00();
    virtual void PadSlot01();
    virtual void PadSlot02();
    virtual void PadSlot03();
    virtual void PadSlot04();
    virtual void PadSlot05();
    virtual void PadSlot06();
    virtual void PadSlot07();
    virtual void PadSlot08();
    virtual void PadSlot09();
    virtual void PadSlot10();
    virtual void PadSlot11();
    virtual void PadSlot12();
    virtual void PadSlot13();
    virtual void PadSlot14();
    virtual void PadSlot15();
    virtual void PadSlot16();
    virtual void PadSlot17();
    virtual void PadSlot18();
    virtual void PadSlot19();
    virtual void PadSlot20();
    virtual void PadSlot21();
    virtual void PadSlot22();
    virtual void PadSlot23();
    virtual void PadSlot24();
    virtual void PadSlot25();
    virtual void PadSlot26();
    virtual void PadSlot27();
    virtual void PadSlot28();
    virtual void PadSlot29();
    virtual void PadSlot30();
    virtual void PadSlot31();
    virtual void PadSlot32();
    virtual void PadSlot33();
    virtual void PadSlot34();
    virtual void TargetMethod(bool a_flag);
};

class BGSSceneActionBase
{
public:
    virtual void Unk_0B();  // slot 0

    std::uint8_t unknown08[0x8];  // 08
    std::uint32_t flags10;  // 10
    std::uint8_t unknown14[0xC];  // 14
    DialogueTarget* target;  // 20
    std::uint8_t unknown28[0x18];  // 28
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
    // BGSSceneActionDialogue::Function3ab500: GUESS(low); compared at RVA 0x3ab500
    void Function3ab500();
};
static_assert(sizeof(BGSSceneActionDialogue) == 0x40, "BGSSceneActionDialogue size");
