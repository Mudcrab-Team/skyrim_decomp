// NiPSysModifierCtlr, ParentLink, Resolve, NiStream: GUESS(low)
// NiPSysModifierCtlr::PostLinkObject: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// _refCount, _pad0C, flags, pad12, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, pad34, target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa0c60 NiPSysModifierCtlr::PostLinkObject

#include "NiPSysModifierCtlr_fa0c60.h"
void NiPSysModifierCtlr::PostLinkObject(NiStream& stream) { ParentLink(stream); if (target) Resolve(); }
