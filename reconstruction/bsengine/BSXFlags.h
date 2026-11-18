// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSXFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSXFlags::CreateClone, BSXFlags::RegisterStreamables, BSXFlags::~BSXFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiCloningProcess, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../netimmerse/NiIntegerExtraData.h"

class NiObject;
class NiCloningProcess;
class NiStream;

class BSXFlags : public NiIntegerExtraData
{
public:
    BSXFlags();
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);  // compared: 0xfd2da0
    virtual bool RegisterStreamables(NiStream& a_stream);  // compared: 0xfd2de0
    virtual ~BSXFlags();  // compared: 0xfd30c0 (scalar deleting destructor)
};
static_assert(sizeof(BSXFlags) == 0x20, "BSXFlags size");
