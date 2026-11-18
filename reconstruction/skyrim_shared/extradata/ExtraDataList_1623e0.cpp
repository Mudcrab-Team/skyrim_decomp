// Origin: original reconstruction; partial declarations adapted from pinned public CommonLibSSE-NG and CommonLibSSE-po3 headers.
// Source exposure: mixed (local binary analysis and public declarations).
// GPL-3.0 declarations: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, include/RE/E/ExtraTerminalState.h.
// Inferred accessor names and stateFlags: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1635e0 ExtraDataList::LockLevel
// 0x164cf0 ExtraDataList::Flag0
// 0x164510 ExtraDataList::OwnerFaction
// 0x164540 ExtraDataList::OwnerNPC
// 0x164d20 ExtraDataList::Flag1
// 0x1623e0 ExtraDataList::Flag2
// 0x169bf0 ExtraDataList::HasInteraction
#include "ExtraDataList_1623e0.h"
std::uint8_t ExtraDataList::LockLevel() { const auto* extra=static_cast<ExtraTerminalState*>(GetByType(79)); if (!extra) return 255; return extra->lockLevel; }
std::uint8_t ExtraDataList::Flag0() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>(extra->stateFlags & 1) : 0; }
std::uint8_t ExtraDataList::Flag1() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>((extra->stateFlags >> 1) & 1) : 0; }
std::uint8_t ExtraDataList::Flag2() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>((extra->stateFlags >> 2) & 1) : 0; }
TESForm* ExtraDataList::OwnerFaction() { const auto* extra=static_cast<ExtraOwnership*>(GetByType(33)); return extra && extra->owner->formType==43 ? extra->owner : nullptr; }
TESForm* ExtraDataList::OwnerNPC() { const auto* extra=static_cast<ExtraOwnership*>(GetByType(33)); return extra && extra->owner->formType==11 ? extra->owner : nullptr; }
bool ExtraDataList::HasInteraction() { bool present=false; if (GetByType(147)) present=true; return present; }
