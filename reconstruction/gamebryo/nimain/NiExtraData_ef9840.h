// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiExtraData: EXE_RTTI
// NiExtraData::name, ::LoadBinary, ::SaveBinary, ::SetName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers: GUESS(low)
#pragma once

#include "bssystem/NiStream_19e930.h"

// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSFixedString
{
public:
    ~BSFixedString();
    BSFixedString& operator=(const BSFixedString& other);
    const char* _data;
};

class NiExtraData : public NiObject
{
public:
    NiExtraData();
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void CopyMembers(NiExtraData* dest);
    ~NiExtraData() override;
    void SetName(const BSFixedString& a_name);

private:
    BSFixedString name;
};
