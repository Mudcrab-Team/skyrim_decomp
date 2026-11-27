// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSScene, BGSScene::Function3a9d30, BGSSceneAction, BGSSceneAction::Function3ab0f0, BGSSceneAction::phaseID, BGSSceneAction::actionFlags, vfunc16, BGSScene::parentScene, BGSScene::aliasID, BGSScene::currentPhase: GUESS(low)
// BGSScene: GUESS(low) CRASHLOGGER_PDB(59818@2026.10.24); placeholder class for the functor BGSScene::RestartActionFunctor::operator
#pragma once

#include <cstdint>
#include <cstddef>

class BGSScene;

class BGSSceneAction
{
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16(BGSScene* scene);
    std::uint32_t phaseID;
    std::uint8_t unk0c[8];
    std::uint8_t actionFlags;
    bool Function3ab0f0(std::uint32_t phase);
};

class BGSScene
{
public:
    BGSScene* parentScene;
    std::uint32_t aliasID;
    std::uint32_t currentPhase;
    int Function3a9d30(BGSSceneAction* action);
};
