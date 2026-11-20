// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xff5020 BSPSysMultiTargetEmitterCtlr::RegisterStreamables
// Adapted bodies: none
#include "BSPSysMultiTargetEmitterCtlr.h"

bool BSPSysMultiTargetEmitterCtlr::RegisterStreamables(NiStream& stream)
{
    return RegisterBaseStreamables(stream) != 0;
}
