// Origin: adapted GetType declaration from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSStandardSoundDef: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BGSStandardSoundDef: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// RegisterType, BGSStandardSoundDefTypeId, BGSStandardSoundDefTypeName: GUESS(low)
extern std::uint32_t BGSStandardSoundDefTypeId;
extern const char BGSStandardSoundDefTypeName[];
void RegisterType(std::uint32_t* id, const char* name, void* context);
class BGSStandardSoundDef { public: std::uint32_t GetType() const; };
