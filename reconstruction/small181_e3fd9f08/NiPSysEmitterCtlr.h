// NiPSysEmitterCtlr: EXE_RTTI
// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// NiPSysEmitterCtlr, NiPSysModifierCtlr: EXE_RTTI
// NiStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysEmitterCtlr::LoadBinary, NiPSysModifierCtlr::LoadBinary: GUESS(low)
// NiStream::ReadEmitter: GUESS(low)
class NiStream { public: void ReadEmitter(); };
class NiPSysModifierCtlr { public: void LoadBinary(NiStream&); };
class NiPSysEmitterCtlr : public NiPSysModifierCtlr { public: void LoadBinary(NiStream&); };
