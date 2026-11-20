// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiBooleanExtraData: EXE_RTTI
// NiBooleanExtraData::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiExtraData_ef9840.h"

class NiBooleanExtraData : public NiExtraData
{
public:
    NiBooleanExtraData();
    ~NiBooleanExtraData() override;

private:
    bool data;
};
