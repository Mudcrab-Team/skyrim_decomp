// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CheckParameterReachedFunctor: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingFunctorBase, state: GUESS(low)
#pragma once

#include <cstdint>

class PathingFunctorBase
{
public:
    PathingFunctorBase();
    virtual ~PathingFunctorBase();

    std::uint32_t state;  // 08
};

class CheckParameterReachedFunctor : public PathingFunctorBase
{
public:
    CheckParameterReachedFunctor();  // compared: 0x11cc6e0
};
