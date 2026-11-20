// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// MagicTarget: EXE_RTTI
// GetOwnerActor: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function01, Function02: GUESS(low)
// MagicTargetIsActor: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class Actor;

class MagicTarget
{
public:
    virtual ~MagicTarget();
    virtual void Function01();  // 01
    virtual void Function02();  // 02
    virtual bool MagicTargetIsActor();  // 03
    Actor* GetOwnerActor();
};
