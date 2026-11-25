// Source exposure: mixed (binary-analysis, community headers).
// Code origin: Stamped as a twin of matched 0xff1810 (gamebryo/nimain/BSBound_ff1810): source copied, names replaced by placeholders.
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// NiStream, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1000e40 Owner1000e40::Function1000e40
// NiExtraData: GUESS(low) STANDIN
#include "Owner1000e40.h"

// guess: same compiled code as matched 0xff1810 apart from relocated fields; its role here is not established.
bool Owner1000e40::Function1000e40(NiStream& stream)
{
    return !NiExtraData::RegisterStreamables(stream);
}
