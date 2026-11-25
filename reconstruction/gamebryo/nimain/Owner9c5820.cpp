// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xef7180 (gamebryo/nimain/NiStringExtraData_ef7180): source copied, names replaced by placeholders.
// 0x9c5820 Owner9c5820::SaveBinary
#include "Owner9c5820.h"

// SaveFixedString_9c5820: GUESS(low) STANDIN
void SaveFixedString_9c5820(NiStream& stream, const BSFixedString& value);

Owner9c5820::Owner9c5820() = default;

// guess: same compiled code as matched 0xef7180 apart from relocated fields; its role here is not established.
void Owner9c5820::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    return SaveFixedString_9c5820(stream, value);
}

Owner9c5820::~Owner9c5820()
{

}
