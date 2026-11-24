// Source exposure: mixed
// Code origin: original declaration view from the pinned image and labelled community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script, Script::~Script: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unkStorage: GUESS(low); opaque layout because the wrapper delegates all member cleanup.
#pragma once

class Script
{
public:
    Script();
    virtual ~Script();

private:
    unsigned char unkStorage[0x80 - sizeof(void*)];
};

static_assert(sizeof(Script) == 0x80, "Object size for sized deallocation");
