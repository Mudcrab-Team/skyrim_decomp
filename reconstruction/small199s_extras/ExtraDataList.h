// Origin: original reconstruction; partial declarations adapted from pinned public CommonLibSSE-NG and CommonLibSSE-po3 headers.
// Source exposure: mixed (local binary analysis and public declarations).
// GPL-3.0 declarations: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, include/RE/E/ExtraTerminalState.h.
// Inferred accessor names and stateFlags: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BSExtraData, next, TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType, ExtraPackage, unk10, index, target, ExtraOwnership, owner, ExtraDataList, GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
// ExtraTerminalState, flags, lockLevel, pad12, pad14: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
class ExtraTerminalState : public BSExtraData { public: std::uint8_t flags; std::uint8_t lockLevel; std::uint16_t pad12; std::uint32_t pad14; };
class TESPackage;
// stateFlags: GUESS(low)
class ExtraPackage : public BSExtraData { public: TESPackage* unk10; std::int32_t index; std::uint32_t target; std::uint8_t stateFlags; };
class TESForm { public: virtual ~TESForm(); void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; };
class ExtraOwnership : public BSExtraData { public: TESForm* owner; };
// LockLevel, Flag0, Flag1, Flag2, OwnerFaction, OwnerNPC, HasInteraction: GUESS(low)
class ExtraDataList { public:
 BSExtraData* GetByType(std::uint32_t type);
 std::uint8_t LockLevel(); std::uint8_t Flag0(); std::uint8_t Flag1(); std::uint8_t Flag2();
 TESForm* OwnerFaction(); TESForm* OwnerNPC(); bool HasInteraction();
};
