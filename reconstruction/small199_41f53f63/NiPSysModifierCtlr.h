// NiPSysModifierCtlr, PostLinkObject, ParentLink, Resolve, NiStream: GUESS(low)
// _refCount, _pad0C, flags, pad12, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, pad34, target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// NiPSysModifierCtlr, PostLinkObject, ParentLink, Resolve, NiStream: GUESS(low)
// _refCount, _pad0C, flags, pad12, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, pad34, target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class NiStream;
class NiObjectNET;
class NiPSysModifierCtlr {
public:
    virtual ~NiPSysModifierCtlr();
    void PostLinkObject(NiStream&);
    void ParentLink(NiStream&);
    void Resolve();
    volatile std::uint32_t _refCount;
    std::uint32_t _pad0C;
    std::uint16_t flags, pad12;
    float frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime;
    std::uint32_t pad34;
    NiObjectNET* target;
};
