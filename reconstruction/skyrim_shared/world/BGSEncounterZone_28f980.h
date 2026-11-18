// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BGSEncounterZone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <cstdint>
// TESFileContainer, array: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFileArray;
struct TESFileContainer { TESFileArray* array; };
// TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm { public: virtual ~TESForm(); TESFileContainer sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetDetachTime: GUESS(low)
class TESObjectCELL { public: std::uint32_t GetDetachTime() const; };
// ENCOUNTER_ZONE_DATA, zoneOwner, location, ownerRank, minLevel, flags, maxLevel, pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFaction;
class BGSLocation;
struct ENCOUNTER_ZONE_DATA { TESFaction* zoneOwner; BGSLocation* location; std::int8_t ownerRank; std::int8_t minLevel; std::uint8_t flags; std::int8_t maxLevel; std::uint32_t pad14; };
// ENCOUNTER_ZONE_GAME_DATA, detachTime, attachTime, resetTime, zoneLevel, pad0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct ENCOUNTER_ZONE_GAME_DATA { std::uint32_t detachTime; std::uint32_t attachTime; std::uint32_t resetTime; std::uint16_t zoneLevel; std::uint16_t pad0D; };
// BGSEncounterZone, data, gameData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function28f980: GUESS(low)
class BGSEncounterZone : public TESForm { public: bool Function28f980(TESObjectCELL* cell); ENCOUNTER_ZONE_DATA data; ENCOUNTER_ZONE_GAME_DATA gameData; };
