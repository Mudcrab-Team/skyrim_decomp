// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene, BGSSceneAction, BGSSceneAction::Loops, BGSSceneAction::GetType, BGSSceneAction::Unk_10, BGSSceneAction::Unk_11, BGSSceneAction::Unk_0D, BGSSceneAction::unk14, BGSScene::actions, BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares Unk_xx without parameters and GetType returns an enum
// BGSScene::PrepareAction: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSScene;

class BGSSceneAction
{
public:
    virtual ~BGSSceneAction();  // 00
    virtual void unk01();  // 01
    virtual void unk02();  // 02
    virtual void unk03();  // 03
    virtual void unk04();  // 04
    virtual bool Loops();  // 05
    virtual bool unk06();  // 06
    virtual std::uint32_t GetType();  // 07
    virtual void unk08();  // 08
    virtual void unk09();  // 09
    virtual void unk0A();  // 0A
    virtual void unk0B();  // 0B
    virtual void unk0C();  // 0C
    virtual void Unk_0D(BGSScene* scene);  // 0D
    virtual void unk0E();  // 0E
    virtual void unk0F();  // 0F
    virtual void Unk_10(BGSScene* scene);  // 10
    virtual void Unk_11(BGSScene* scene);  // 11

    std::uint8_t pad08[0x0C];
    std::uint8_t unk14;  // 14
};

// BGSScene here is a stand-in for the closure-like receiver whose first member is the scene
// pointer; the placeholder class name of the unit is kept.
class BGSScene
{
public:
    int PrepareAction(BGSSceneAction* action);  // compared: 0x3a99a0

    BGSScene* scene;  // 0x00
};
