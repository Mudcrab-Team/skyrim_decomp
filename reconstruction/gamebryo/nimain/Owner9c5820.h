// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations. Stamped as a twin of matched 0xef7180 (gamebryo/nimain/NiStringExtraData_ef7180): source copied, names replaced by placeholders.
// ::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner9c5820, SaveFixedString_9c5820: GUESS(low) STANDIN
#pragma once
#include "NiStringExtraData_ef7180.h"

class Owner9c5820 : public NiExtraData
{
public:
    Owner9c5820();
    void SaveBinary(NiStream& stream) override;
    ~Owner9c5820() override;

private:
    BSFixedString value;
};

