// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of Function3ab500.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSceneActionDialogue, GetType, GetEmotionType, GetEmotionValue, Loops, FacesTarget, Unk_0B, ~BGSSceneActionDialogue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSceneActionBase, DialogueTopicTarget, EmotionType, Function3ab500, flags10, topic, unknown08, unknown14, unknown18, unknown28: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

enum class EmotionType : std::uint32_t
{
    kNone = 0,
};

class DialogueTopicTarget
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23(bool a_flag);
};

class BGSSceneActionBase
{
public:
    virtual void Unk_0B();  // slot 0

    std::uint8_t unknown08[0x8];  // 08
    std::uint32_t flags10;  // 10
    std::uint32_t unknown14;  // 14
    std::uint64_t unknown18;  // 18
    DialogueTopicTarget* topic;  // 20
    std::uint8_t unknown28[0x18];  // 28
};
static_assert(sizeof(BGSSceneActionBase) == 0x40, "BGSSceneActionBase size");

class BGSSceneActionDialogue : public BGSSceneActionBase
{
public:
    BGSSceneActionDialogue();
    enum class Type : std::uint32_t {};
    virtual Type GetType() const;  // compared: 0x3ab520
    virtual EmotionType GetEmotionType() const;  // compared: 0x3ab280
    virtual std::uint32_t GetEmotionValue() const;  // compared: 0x3ab290
    virtual bool Loops() const;  // compared: 0x3ab530
    virtual bool FacesTarget() const;  // compared: 0x3ab2a0
    virtual void Unk_0B();  // compared: 0x3abcf0
    virtual ~BGSSceneActionDialogue() {}  // compared: 0x3ab1c0 (scalar deleting destructor)
    void Function3ab500();
};
static_assert(sizeof(BGSSceneActionDialogue) == 0x40, "BGSSceneActionDialogue size");
