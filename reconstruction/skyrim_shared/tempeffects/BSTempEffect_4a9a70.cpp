// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a9a70 BSTempEffect::CreateEffectForLoadGame
// Adapted bodies: BSTempEffect::CreateEffectForLoadGame follows fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffect.cpp:165
#include "BSTempEffect_4a9a70.h"

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

BSTempEffect* BSTempEffect::CreateEffectForLoadGame(TEMP_EFFECT_TYPE aeType)
{
    unsigned char ucType = aeType;
    InitializeFactories();
    if (ucType < 12)
    {
        ITempEffectFactory* pFactory = pTempEffectFactoriesA[ucType];
        if (pFactory)
            return pFactory->Create();
    }
    return 0;
}
