// Origin: adapted GetType declaration from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSStandardSoundDef: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x32c290 BGSStandardSoundDef::GetType
#include "BGSStandardSoundDef_32c290.h"
std::uint32_t BGSStandardSoundDef::GetType() const {
  if (!BGSStandardSoundDefTypeId) RegisterType(&BGSStandardSoundDefTypeId, BGSStandardSoundDefTypeName, nullptr);
  return BGSStandardSoundDefTypeId;
}
