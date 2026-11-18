// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiStringExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiStringExtraData::IsEqual, NiStringExtraData::LoadBinary, NiStringExtraData::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "NiExtraData.h"

class NiStringExtraData : public NiExtraData
{
public:
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xef71c0
    virtual void LoadBinary(NiStream& a_stream);  // compared: 0xef70e0
    virtual bool RegisterStreamables(NiStream& a_stream);  // compared: 0xef7130

    BSFixedString value;  // 18
};
static_assert(sizeof(NiStringExtraData) == 0x20, "NiStringExtraData size");
