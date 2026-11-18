// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWindModifier, NiPSysModifier, strength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers, CopyBase: GUESS(low)
#pragma once
#include <cstdint>
// NiRefObject, _refCount, _pad0C, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData, name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyBase: GUESS(low)
class NiRefObject { public: virtual ~NiRefObject(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject {};
class NiExtraData : public NiObject { public: const char* name; };
// NiPSysModifier, name, order, target, active: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiParticleSystem;
class NiPSysModifier : public NiObject { public: const char* name; std::uint32_t order; std::uint32_t pad1C; NiParticleSystem* target; bool active; };

class BSWindModifier : public NiPSysModifier {
public:
    void CopyMembers(BSWindModifier* a_dest);
    float strength;
};
void CopyBase(NiPSysModifier* a_source, NiPSysModifier* a_dest);
