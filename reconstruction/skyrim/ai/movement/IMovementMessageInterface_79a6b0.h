// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IMovementMessageInterface, IMovementInterface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// IMovementInterface: STANDIN EXE_RTTI; only its out-of-line destructor is declared
// IMovementInterface::~IMovementInterface: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct IMovementInterface
{
public:
    IMovementInterface();
    virtual ~IMovementInterface();
};

class IMovementMessageInterface : public IMovementInterface
{
public:
    IMovementMessageInterface();
    ~IMovementMessageInterface() override {}

};
static_assert(sizeof(IMovementMessageInterface) == 0x8, "IMovementMessageInterface size from the deleting destructor");
