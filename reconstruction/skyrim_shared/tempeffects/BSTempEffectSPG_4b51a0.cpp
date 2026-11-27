// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4b51a0 BSTempEffectSPG::LoadGame
// Adapted bodies: BSTempEffectSPG::LoadGame follows fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffectSPG.cpp:175
#include "BSTempEffectSPG_4b51a0.h"

void BSTempEffectSPG::LoadGame(BGSLoadGameBuffer* apLoadGameBuffer)
{
    BSTempEffect::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->LoadFormID(this->pSPGData);
    apLoadGameBuffer->LoadDataEndian(&this->fTotalFadeTime, 4, 4);
    apLoadGameBuffer->LoadDataEndian(&this->fFadeTime, 4, 4);
    apLoadGameBuffer->LoadDataEndian(&this->bFadeIn, 1, 1);
}
