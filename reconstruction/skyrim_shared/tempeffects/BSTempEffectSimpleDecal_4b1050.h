// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSTempEffectSimpleDecal::ReleaseGlobalPreloadParent: CRASHLOGGER_PDB(59818@2026.10.24)
// PreloadParent, refCount, preloadParent: GUESS(low)
#pragma once

#include <cstdint>

class PreloadParent
{
public:
    virtual ~PreloadParent();

    volatile long refCount;
};

class BSTempEffectSimpleDecal
{
public:
    static void ReleaseGlobalPreloadParent();

    static PreloadParent* preloadParent;
};
