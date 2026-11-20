// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build.
// 0xef7180 NiStringExtraData::SaveBinary
// 0xef73d0 NiStringExtraData::dtor
#include "NiStringExtraData_ef7180.h"

// SaveFixedString: GUESS(low); serializes the fixed-string value.
void SaveFixedString(NiStream& stream, const BSFixedString& value);
NiStringExtraData::NiStringExtraData() = default;

void NiStringExtraData::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    return SaveFixedString(stream, value);
}

NiStringExtraData::~NiStringExtraData()
{

}
