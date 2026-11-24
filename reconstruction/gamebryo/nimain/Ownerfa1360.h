// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations. Stamped as a twin of matched 0xef9b00 (gamebryo/nimain/NiExtraData_ef9840): source copied, names replaced by placeholders.
// ::LoadBinary, ::SaveBinary, ::SetName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Ownerfa1360: GUESS(low) STANDIN
// CopyMembers: GUESS(low) STANDIN
#pragma once
#include "NiExtraData_ef9840.h"

class Ownerfa1360 : public NiObject
{
public:
    Ownerfa1360();
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void CopyMembers(Ownerfa1360* dest);
    ~Ownerfa1360() override;
    void SetName(const BSFixedString& a_name);

private:
    BSFixedString name;
};

