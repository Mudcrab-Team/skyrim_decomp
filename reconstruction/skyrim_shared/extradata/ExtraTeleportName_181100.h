// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: public declarations and observed comparison field offsets.
// ExtraTeleportName, ExtraTeleportName::IsNotEqual, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraTeleportName::message: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMessage: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "BSExtraData.h"

class BGSMessage;

class ExtraTeleportName : public BSExtraData
{
public:
    bool IsNotEqual(const BSExtraData* other) const override;

private:
    BGSMessage* message;
};
