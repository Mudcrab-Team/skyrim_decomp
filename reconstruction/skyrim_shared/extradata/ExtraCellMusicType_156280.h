// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: public declarations and observed comparison field offsets.
// ExtraCellMusicType, ExtraCellMusicType::IsNotEqual, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraCellMusicType::type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMusicType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "BSExtraData.h"

class BGSMusicType;

class ExtraCellMusicType : public BSExtraData
{
public:
    bool IsNotEqual(const BSExtraData* other) const override;

private:
    BGSMusicType* type;
};
