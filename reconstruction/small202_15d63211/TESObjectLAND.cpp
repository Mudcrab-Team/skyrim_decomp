// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// TESObjectLAND: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2ab510 TESObjectLAND::Function2ab510
#include "TESObjectLAND.h"
void TESObjectLAND::Function2ab510(std::uint8_t first, std::uint16_t second) {
 UpdateData(first, second, loadedData);
 FinishUpdate();
}
