// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiInterpolator, NiObject, NiRefObject, lastTime, pad14, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiInterpolator::NiInterpolator: GUESS(low)
#pragma once
#include <cstdint>
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject { public: NiObject(); virtual ~NiObject(); };
class NiInterpolator : public NiObject { public: NiInterpolator(); float lastTime; std::uint32_t pad14; };
