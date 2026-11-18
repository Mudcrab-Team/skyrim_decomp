// Source exposure: mixed
// Origin: authorized sibling and community declarations
// BGSQuestPerkEntry::ApplyPerkEntry: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:260
// BGSPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BGSPerkEntry.h
// names: GUESS(low); derived declarations and signatures remain provisional
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class Actor; class TESFile; class BGSPerk;
class TESQuest { public: bool EnsureQuestStarted(bool& delayed, bool value); void SetStage(std::uint16_t stage); };
class BGSPerkEntry {
public:
    virtual bool CheckConditionFilters(std::uint32_t, void*);
    virtual int GetFunction();
    virtual void* GetFunctionData() const;
    virtual ~BGSPerkEntry();
    virtual int GetType() const = 0;
    virtual void ClearData();
    virtual void InitItem(TESFile*);
    virtual bool Load(TESFile*);
    virtual void SetParent(BGSPerk*);
    virtual std::uint16_t GetID() const;
    virtual void ApplyPerkEntry(Actor*) = 0;
    virtual void RemovePerkEntry(Actor*) = 0;
    struct Header { std::uint8_t rank; std::uint8_t priority; std::uint16_t unknown; std::uint32_t reserved; } header;
};
class BGSQuestPerkEntry : public BGSPerkEntry {
public:
    void ApplyPerkEntry(Actor*) override;
    struct Data { TESQuest* quest; std::uint16_t stage; } data;
};
