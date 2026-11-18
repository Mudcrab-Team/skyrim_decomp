/*
 * MagicCaster: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x5cd180 30 bytes.
 * Origin: original reconstruction.
 * Source exposure: mixed (binary-analysis and community-headers).
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Partial declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT). Stand-ins are unverified.
 */
// MagicCaster: GUESS(low) STANDIN
#pragma once

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

#include <cstdint>
// Actor, MagicItem, TESObjectREFR, BaseFormComponent, TESFileContainer, TESFileArray, TESForm, array, sourceFiles, formFlags, formID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class Actor; class MagicItem; class TESObjectREFR; class TESFileArray;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESFileContainer { public: TESFileArray* array; };
class TESForm : public BaseFormComponent { public: TESFileContainer sourceFiles; std::uint32_t formFlags; std::uint32_t formID; };
// MagicSystem, CannotCastReason: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
namespace MagicSystem { enum class CannotCastReason : std::uint32_t; }
// MagicCaster, CastSpellImmediate, FindTouchTarget, RequestCastImpl, StartChargeImpl, StartReadyImpl, StartCastImpl, FinishCastImpl, InterruptCastImpl, SpellCast, CheckCast, GetCasterStatsObject, GetCasterAsActor, GetCasterObjectReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class MagicCaster { public:
 virtual ~MagicCaster();
 virtual void CastSpellImmediate(MagicItem*, bool, TESObjectREFR*, float, bool, float, Actor*);
 virtual void FindTouchTarget();
 virtual void RequestCastImpl();
 virtual bool StartChargeImpl();
 virtual void StartReadyImpl();
 virtual void StartCastImpl();
 virtual void FinishCastImpl();
 virtual void InterruptCastImpl(bool);
 virtual void SpellCast(bool, std::uint32_t, MagicItem*);
 virtual bool CheckCast(MagicItem*, bool, float*, MagicSystem::CannotCastReason*, bool);
 virtual TESObjectREFR* GetCasterStatsObject() const;
 virtual Actor* GetCasterAsActor() const;
 virtual TESObjectREFR* GetCasterObjectReference(Actor**) const;
 // Function5cd180: GUESS(low)
 std::uint32_t Function5cd180();
};
