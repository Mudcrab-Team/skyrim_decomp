// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES, TES::interiorCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL, TESObjectCELL::GetbhkWorld: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// bhkWorld, TES::SetCollisionEnabled, gTES, gExteriorbhkWorld, gCollisionDisabled, bhkWorld::collisionDisabled: GUESS(low); globals at RVAs 0x32303b8, 0x21a0598, 0x20d1bf0
#pragma once

#include <cstdint>
#include <cstddef>

class bhkWorld
{
public:
    std::uint8_t pad00[0xC701];
    std::uint8_t collisionDisabled;  // 0xC701
};

class TESObjectCELL
{
public:
    bhkWorld* GetbhkWorld() const;
};

class TES;
extern TES* gTES;
extern bhkWorld** gExteriorbhkWorld;
extern bool gCollisionDisabled;

class TES
{
public:
    void SetCollisionEnabled(bool enabled);  // compared: 0x1a72d0

    std::uint8_t pad00[0xC0];
    TESObjectCELL* interiorCell;  // 0xC0
};
