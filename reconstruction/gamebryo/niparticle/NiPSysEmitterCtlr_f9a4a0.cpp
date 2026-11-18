// NiPSysEmitterCtlr: EXE_RTTI
// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf9a4a0 NiPSysEmitterCtlr::LoadBinary

#include "NiPSysEmitterCtlr_f9a4a0.h"

void NiPSysEmitterCtlr::LoadBinary(NiStream& stream) { NiPSysModifierCtlr::LoadBinary(stream); stream.ReadEmitter(); }
