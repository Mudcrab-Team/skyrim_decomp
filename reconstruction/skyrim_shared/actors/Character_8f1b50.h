// Character: GUESS(low) STANDIN
/*
 * Character: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x8f1b50 19 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra; unit isolation by gpt-6.1-sol.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Partial interfaces are stand-ins.
 */
#pragma once
#include <cstdint>
// CharacterRelated, Character, Character::Related, Character::Forward2e87b0, CharacterRelated::Call22d840: GUESS(low) STANDIN
class TESCombatStyle;
class CharacterRelated { public: void* Call22d840(); };
class Character { public: float Call8f1b50(); TESCombatStyle* GetCombatStyle(); float Call8f1ad0(); float Forward8f21f0(); float Forward8f24c0(); float Forward8f25a0(); CharacterRelated* Related(); void* Forward2e87b0(); };

// Character::Call8f1b50, Character::Call8f1ad0, Character::Forward8f21f0, Character::Forward8f24c0, Character::Forward8f25a0: GUESS(low) STANDIN
// AdjustValue, limit21a, limit21b, limit24a, limit24b, limit25a, limit25b: GUESS(low) STANDIN
float AdjustValue(float, float, float);
extern float limit21a, limit21b, limit24a, limit24b, limit25a, limit25b;

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

// BaseFormComponent, TESForm, TESCombatStyle, CombatStyleGeneralData, CombatStyleMeleeData, CombatStyleCloseRangeData, CombatStyleLongRangeData, CombatStyleFlightData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESCombatStyle::generalData, CombatStyleGeneralData::defensiveMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Character::GetCombatStyle: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91, permission)
// BaseFormComponent has the documented base fields and a partial virtual interface. TESForm omits unneeded virtual methods.
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(BaseFormComponent*); };
class TESFileArray;
class TESForm : public BaseFormComponent { public: TESFileArray* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
struct CombatStyleGeneralData { float offensiveMult, defensiveMult, groupOffensiveMult, meleeScoreMult, magicScoreMult, rangedScoreMult, shoutScoreMult, unarmedScoreMult, staffScoreMult, avoidThreatChance; };
struct CombatStyleMeleeData { float attackIncapacitatedMult, powerAttackIncapacitatedMult, powerAttackBlockingMult, bashMult, bashRecoilMult, bashAttackMult, bashPowerAttackMult, specialAttackMult; };
struct CombatStyleCloseRangeData { float circleMult, fallbackMult, flankDistanceMult, stalkTimeMult; };
struct CombatStyleLongRangeData { float strafeMult; };
struct CombatStyleFlightData { float hoverChance, diveBombChance, groundAttackChance, hoverTimeMult, groundAttackTimeMult, perchAttackChance, perchAttackTimeMult, flyingAttackChance; };
class TESCombatStyle : public TESForm { public: CombatStyleGeneralData generalData; CombatStyleMeleeData meleeData; CombatStyleCloseRangeData closeRangeData; CombatStyleLongRangeData longRangeData; CombatStyleFlightData flightData; std::uint32_t flags; };
static_assert(sizeof(TESForm) == 0x20, "TESForm size");
static_assert(sizeof(TESCombatStyle) == 0xa0, "TESCombatStyle size");
// BaseFormComponent::InitializeDataComponent, BaseFormComponent::ClearDataComponent, BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType, TESForm::pad1B, TESForm::pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESCombatStyle::generalData, TESCombatStyle::meleeData, TESCombatStyle::closeRangeData, TESCombatStyle::longRangeData, TESCombatStyle::flightData, TESCombatStyle::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleGeneralData::offensiveMult, CombatStyleGeneralData::defensiveMult, CombatStyleGeneralData::groupOffensiveMult, CombatStyleGeneralData::meleeScoreMult, CombatStyleGeneralData::magicScoreMult, CombatStyleGeneralData::rangedScoreMult, CombatStyleGeneralData::shoutScoreMult, CombatStyleGeneralData::unarmedScoreMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleGeneralData::staffScoreMult, CombatStyleGeneralData::avoidThreatChance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleMeleeData::attackIncapacitatedMult, CombatStyleMeleeData::powerAttackIncapacitatedMult, CombatStyleMeleeData::powerAttackBlockingMult, CombatStyleMeleeData::bashMult, CombatStyleMeleeData::bashRecoilMult, CombatStyleMeleeData::bashAttackMult, CombatStyleMeleeData::bashPowerAttackMult, CombatStyleMeleeData::specialAttackMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleCloseRangeData::circleMult, CombatStyleCloseRangeData::fallbackMult, CombatStyleCloseRangeData::flankDistanceMult, CombatStyleCloseRangeData::stalkTimeMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleLongRangeData::strafeMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatStyleFlightData::hoverChance, CombatStyleFlightData::diveBombChance, CombatStyleFlightData::groundAttackChance, CombatStyleFlightData::hoverTimeMult, CombatStyleFlightData::groundAttackTimeMult, CombatStyleFlightData::perchAttackChance, CombatStyleFlightData::perchAttackTimeMult, CombatStyleFlightData::flyingAttackChance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESFileArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
