// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffect.cpp:165
// BSTempEffect, BSTempEffect::CreateEffectForLoadGame, TEMP_EFFECT_TYPE, ITempEffectFactory, ITempEffectFactory::Create: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// kNone: GUESS(low)
#pragma once

enum TEMP_EFFECT_TYPE
{
    kNone = 0
};

class BSTempEffect;

class ITempEffectFactory
{
public:
    virtual ~ITempEffectFactory();           // 00
    virtual BSTempEffect* Create() = 0;      // 01
};

class BSTempEffect
{
public:
    static BSTempEffect* CreateEffectForLoadGame(TEMP_EFFECT_TYPE aeType);
};
