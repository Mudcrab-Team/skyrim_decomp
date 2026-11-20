// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiStringExtraData: EXE_RTTI
// NiStringExtraData::value, ::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

#pragma once

#include "NiExtraData_ef9840.h"

class NiStringExtraData : public NiExtraData
{
public:
    NiStringExtraData();
    void SaveBinary(NiStream& stream) override;
    ~NiStringExtraData() override;

private:
    BSFixedString value;
};
