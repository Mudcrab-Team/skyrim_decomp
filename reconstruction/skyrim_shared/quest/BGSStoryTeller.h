// Code origin: names, bases, slot order and member layout adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStoryTeller, BGSStoryTeller::ProcessEvent, BGSStoryTeller::~BGSStoryTeller, BGSStoryTeller::queuedStartQuests, BGSStoryTeller::runningQuests, BGSStoryTeller::queuedStopQuests, BGSStoryTeller::infoClearQuests, BGSStoryTeller::helloTopicQuests, BGSStoryTeller::greetingTopicQuests, BGSStoryTeller::startUpQuestsInitialized, BGSStoryTeller::questStageWaitMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTEventSink, BSTSingletonSDM, BSTArray, BSTScatterTable, BSEventNotifyControl, TESQuestStageItemDoneEvent, TESQuest: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// QuestStageItemDone, TESQuestStageItemDoneEvent members (formID, stage, flag): GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESQuest;

enum class BSEventNotifyControl : int
{
    kContinue = 0,
    kStop = 1
};

// Fields read by ProcessEvent: a form id, a stage and a flag byte; NG leaves the event opaque.
struct TESQuestStageItemDoneEvent
{
    std::uint32_t formID;  // 00
    std::uint16_t stage;  // 04
    std::uint8_t flag;  // 06
    std::uint8_t pad07;  // 07
};
static_assert(sizeof(TESQuestStageItemDoneEvent) == 0x8, "event size");

template <class Event> class BSTEventSource;

template <class Event>
class BSTEventSink
{
public:
    virtual ~BSTEventSink() = default;  // 00
    virtual BSEventNotifyControl ProcessEvent(const Event* a_event, BSTEventSource<Event>* a_eventSource) = 0;  // 01
};

// Empty singleton base: NG places it at 08, so it is kept as a one-byte member here.
class BSTSingletonSDM
{
};

template <class T>
class BSTArray
{
public:
    T* _data;  // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint32_t _size;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BSTArray<TESQuest*>) == 0x18, "BSTArray size");

// BSTHashMap<std::uint32_t, BSTArray<...>*> table state with the heap allocator (NG: BSTScatterTable).
struct BSTScatterTable
{
    std::uint64_t _pad00;  // 00
    std::uint32_t _pad08;  // 08
    std::uint32_t _capacity;  // 0C
    std::uint32_t _free;  // 10
    std::uint32_t _good;  // 14
    const void* _sentinel;  // 18
    std::uint64_t _allocatorPad00;  // 20
    void* _allocatorEntries;  // 28
};
static_assert(sizeof(BSTScatterTable) == 0x30, "BSTScatterTable size");

class BGSStoryTeller : public BSTEventSink<TESQuestStageItemDoneEvent>
{
public:
    ~BGSStoryTeller() override;  // 00
    BSEventNotifyControl ProcessEvent(const TESQuestStageItemDoneEvent* a_event, BSTEventSource<TESQuestStageItemDoneEvent>* a_eventSource) override;  // 01, compared: 0x53a270

    // address 0x53c370: handles one finished quest stage item; the name is a guess.
    void QuestStageItemDone(std::uint32_t a_formID, std::uint16_t a_stage, std::uint8_t a_flag);

    BSTSingletonSDM singletonBase;  // 08
    std::uint8_t pad09;  // 09
    std::uint16_t pad0A;  // 0A
    std::uint32_t pad0C;  // 0C
    BSTArray<TESQuest*> queuedStartQuests;  // 10
    BSTArray<TESQuest*> runningQuests;  // 28
    BSTArray<TESQuest*> queuedStopQuests;  // 40
    BSTArray<TESQuest*> infoClearQuests;  // 58
    BSTArray<TESQuest*> helloTopicQuests;  // 70
    BSTArray<TESQuest*> greetingTopicQuests;  // 88
    bool startUpQuestsInitialized;  // A0
    std::uint8_t padA1;  // A1
    std::uint16_t padA2;  // A2
    std::uint32_t padA4;  // A4
    BSTScatterTable questStageWaitMap;  // A8
};
static_assert(sizeof(BGSStoryTeller) == 0xD8, "BGSStoryTeller size");
static_assert(offsetof(BGSStoryTeller, queuedStartQuests) == 0x10, "queuedStartQuests offset");
static_assert(offsetof(BGSStoryTeller, questStageWaitMap) == 0xA8, "questStageWaitMap offset");
