// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x180eb0 ExtraLock::~ExtraLock
// Adapted bodies: ExtraLock::~ExtraLock follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:3524
#include "ExtraLock_180eb0.h"

ExtraLock::~ExtraLock()
{
    REFR_LOCK* oldLock = lock;
    ::operator delete(oldLock, 0x20);
}
