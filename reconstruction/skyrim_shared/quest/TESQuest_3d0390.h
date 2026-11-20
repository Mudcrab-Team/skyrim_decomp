// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations follow the existing TESQuest layout and the cited public headers.
// TESQuest, QUEST_DATA, QUEST_DATA::flags, currentStage, aliases, scenes, instanceData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest::GetCurrentStageID, IsActive, SetEnabled, AcceptVisitor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStoryManagerTreeVisitor, BGSStoryManagerTreeVisitor::VisitControl, VisitBranchNode, VisitQuestNode, VisitQuest: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSScene, BGSScene::flags, BGSScene::isPlaying, BGSBaseAlias, BGSBaseAlias::aliasName, aliasID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString, BSFixedString::_data, BGSQuestInstanceText, BGSQuestInstanceText::id, BSTArray, BSTArray::data, BSTArray::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, padding: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class TESQuest;
class BGSStoryManagerBranchNode;
class BGSStoryManagerQuestNode;

class BGSStoryManagerTreeVisitor
{
public:
    enum class VisitControl : std::int32_t {};

    virtual ~BGSStoryManagerTreeVisitor();
    virtual VisitControl VisitBranchNode(BGSStoryManagerBranchNode& node);
    virtual VisitControl VisitQuestNode(BGSStoryManagerQuestNode& node, bool mode);
    virtual VisitControl VisitQuest(TESQuest& quest);
};

struct QUEST_DATA
{
    float questDelayTime;
    std::uint16_t flags;
    std::int8_t priority;
    std::uint8_t questType;
};
static_assert(sizeof(QUEST_DATA) == 8, "quest data size");

template<class T> struct BSTArray
{
    T* data;
    std::uint8_t padding08[8];
    std::uint32_t size;
    std::uint8_t padding14[4];
};
static_assert(sizeof(BSTArray<void*>) == 0x18, "array layout");

struct BSFixedString
{
    const char* _data;
};

class BGSBaseAlias
{
public:
    virtual ~BGSBaseAlias();
    BSFixedString aliasName;
    TESQuest* owningQuest;
    std::uint32_t aliasID;
};

struct BGSQuestInstanceText
{
    std::uint32_t id;
};

class BGSScene
{
public:
    void Function3a8060(bool start);
    void Function3a7970();
    void Function3a8830(std::uint32_t action);

    std::uint8_t padding00[0xA0];
    std::uint32_t flags;
    std::uint8_t paddingA4[0xC];
    bool isPlaying;
};

// TESForm, TESForm::AddChange: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FunctionSlot declarations: GUESS(low)
class TESForm
{
public:
    virtual ~TESForm();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual void FunctionSlot06();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    virtual void FunctionSlot09();
    virtual bool AddChange(std::uint32_t flags);

private:
    std::uint8_t padding008[0x18];
};
static_assert(sizeof(TESForm) == 0x20, "form prefix size");

class TESQuest : public TESForm
{
public:
    void SetEnabled(bool enabled);
    bool IsActive() const;
    void Function3d0740(bool active);
    std::uint16_t GetCurrentStageID() const;
    static std::int32_t Function3d1630(const bool* start, BGSScene* scene);
    static std::int32_t Function3d1670(const void*, BGSScene* scene);
    static std::int32_t Function3d16a0(const std::uint32_t* action, BGSScene* scene);
    BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& visitor);
    BGSBaseAlias* Function3d3220(const BSFixedString& name) const;
    static std::uint32_t& Function3d88c0(std::uint32_t& value);
    BGSQuestInstanceText* Function3d8ac0(std::uint32_t id);
    const BGSQuestInstanceText* Function3d8b10(std::uint32_t id) const;

private:
    std::uint8_t padding020[0x18];
    BSTArray<BGSQuestInstanceText*> instanceData;
    std::uint8_t padding050[8];
    BSTArray<BGSBaseAlias*> aliases;
    std::uint8_t padding070[0x68];
    QUEST_DATA data;
    std::uint8_t padding0E0[0x128];
    BSTArray<BGSScene*> scenes;
    std::uint8_t padding220[8];
    std::uint16_t currentStage;
};
