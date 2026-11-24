// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene: EXE_RTTI
// BGSSceneAction: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function3a9e40, parent, package, active, actor, Test: GUESS(low)
// Function3a9e40 return type: GUESS(low); the 32-bit width is inferred
#pragma once
#include <cstdint>
class BGSSceneAction {
public:
    virtual void unk00(); virtual void unk01(); virtual void unk02(); virtual void unk03();
    virtual void unk04(); virtual void unk05(); virtual void unk06(); virtual void unk07();
    virtual bool Test(void*, void*, void*);
    std::uint64_t unk08;
    std::uint32_t unk10;
    std::uint8_t flags;
};
class BGSScene {
public:
    std::uint32_t Function3a9e40(BGSSceneAction* action);
    void* parent;
    void* package;
    bool active;
    void* actor;
};
