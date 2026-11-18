// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// NiStringExtraData: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// NiRefObject, NiObject, NiExtraData, NiStringExtraData, BSFixedString, name, value, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Functionef70a0, CopyBase, CopyString, ptr: GUESS(low)
class NiRefObject { public: virtual ~NiRefObject(); volatile std::uint32_t _refCount; std::uint32_t _pad0C; };
class NiObject : public NiRefObject {};
class BSFixedString { public: const char* ptr; };
class NiExtraData : public NiObject { public: BSFixedString name; };
class NiStringExtraData : public NiExtraData {
public:
 void Functionef70a0(NiStringExtraData* target);
 void CopyBase(NiStringExtraData* target);
 char* value;
};
void CopyString(char** target, char** source);
