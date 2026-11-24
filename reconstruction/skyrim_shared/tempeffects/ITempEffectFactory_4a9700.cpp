// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a9700 ITempEffectFactory::GetFactory
// Adapted bodies: ITempEffectFactory::GetFactory follows fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffect.cpp:44
#include "ITempEffectFactory_4a9700.h"

#include <cstring>

// The factory table lives in the image; the unit refers to it by address.
extern ITempEffectFactory* pTempEffectFactoriesA[12];
extern bool bTempEffectFactoriesInitialized;

// The table is zeroed on first use.
static void InitializeFactories()
{
    if (!bTempEffectFactoriesInitialized)
    {
        memset(pTempEffectFactoriesA, 0, sizeof(pTempEffectFactoriesA));
        bTempEffectFactoriesInitialized = true;
    }
}

ITempEffectFactory* ITempEffectFactory::GetFactory(unsigned char aucType)
{
    InitializeFactories();
    if (aucType < 12)
        return pTempEffectFactoriesA[aucType];
    return 0;
}
