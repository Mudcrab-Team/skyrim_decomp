// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a9760 ITempEffectFactory::RegisterFactory
// Adapted bodies: ITempEffectFactory::RegisterFactory follows fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffect.cpp:53
#include "ITempEffectFactory_4a9760.h"

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

void ITempEffectFactory::RegisterFactory(unsigned char aucType, ITempEffectFactory* apFactory)
{
    InitializeFactories();
    if (aucType < 12)
        pTempEffectFactoriesA[aucType] = apFactory;
}
