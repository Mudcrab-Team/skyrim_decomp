// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; declarations informed by CommonLibSSE-NG.
// BSBound, NiExtraData, NiStream, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiExtraData, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xff1810 BSBound::RegisterStreamables
#include "BSBound.h"
bool BSBound::RegisterStreamables(NiStream& stream)
{
    return !NiExtraData::RegisterStreamables(stream);
}
