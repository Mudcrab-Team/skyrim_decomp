// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// Code origin: Stamped as a twin of matched 0xf9a4a0 (gamebryo/niparticle/NiPSysEmitterCtlr_f9a4a0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa9b60 Ownerfa9b60::Functionfa9b60
#include "Ownerfa9b60.h"

// guess: same compiled code as matched 0xf9a4a0 apart from relocated fields; its role here is not established.
void Ownerfa9b60::Functionfa9b60(NiStream& stream) { NiPSysModifierCtlr::LoadBinary(stream); stream.ReadEmitter(); }
