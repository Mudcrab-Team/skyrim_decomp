// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x4181d0 Sky::FinishLoadGame
#include "Sky_4181d0.h"

ReferenceEffectManager* g_referenceEffectManager;

void Sky::FinishLoadGame(BGSLoadFormBuffer* buf)
{
    if (currentReferenceEffect)
    {
        currentReferenceEffect->FinishLoadGame(buf);
        g_referenceEffectManager->Function784ad0(currentReferenceEffect);
    }
    if (lastReferenceEffect)
    {
        lastReferenceEffect->FinishLoadGame(buf);
        g_referenceEffectManager->Function784ad0(lastReferenceEffect);
    }
    if (clouds && (mode == 2 || mode == 3))
    {
        clouds->forceUpdate = true;
        TESWeather* weather = lastWeather ? lastWeather : currentWeather;
        if (weather)
        {
            clouds->Function40cdc0(weather);
        }
    }
    flags &= ~0x400000u;
    Update(0.0f);
}
