// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatExtraData, NiExtraData, value: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers, CopyBase: GUESS(low)
#pragma once
#include <cstdint>
// NiRefObject, _refCount, _pad0C, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData, name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyBase: GUESS(low)
class NiRefObject { public: virtual ~NiRefObject(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject {};
class NiExtraData : public NiObject { public: const char* name; };

class NiFloatExtraData : public NiExtraData {
public:
    void CopyMembers(NiFloatExtraData* a_dest);
    float value;
};
void CopyBase(NiExtraData* a_source, NiExtraData* a_dest);
