// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ITweenerNodeFollowerSetup: EXE_RTTI
// IMovementInterface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// IMovementInterface: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

struct IMovementInterface
{
public:
    IMovementInterface();
    virtual ~IMovementInterface();
};

class ITweenerNodeFollowerSetup : public IMovementInterface
{
public:
    ITweenerNodeFollowerSetup();
    ~ITweenerNodeFollowerSetup() override {}
};
static_assert(sizeof(ITweenerNodeFollowerSetup) == 0x8, "ITweenerNodeFollowerSetup size from the deleting destructor");
