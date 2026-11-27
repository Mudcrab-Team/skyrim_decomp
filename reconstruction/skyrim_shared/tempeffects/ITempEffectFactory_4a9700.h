// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TempEffects/BSTempEffect.cpp:44
// ITempEffectFactory, ITempEffectFactory::GetFactory: SIBLING(fo4-private@1b765c70, author-permission); stand-in reduced to the static the body defines
#pragma once

class ITempEffectFactory
{
public:
    static ITempEffectFactory* GetFactory(unsigned char aucType);
};
