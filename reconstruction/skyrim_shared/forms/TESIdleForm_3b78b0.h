/*
 * TESIdleForm: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x3b78b0 23 bytes.
 * Origin: original reconstruction.
 * Source exposure: mixed (binary-analysis and community-headers).
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Partial declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT). Stand-ins are unverified.
 */
// TESIdleForm: GUESS(low) STANDIN
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
// BaseFormComponent, TESFileArray, TESFileContainer, array, TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class TESFileArray;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESFileContainer { public: TESFileArray* array; };
class TESForm : public BaseFormComponent { public: TESFileContainer sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; };
// TESConditionItem, TESCondition, head, IDLE_DATA, loopMin, loopMax, flags, animationGroupSelection, replayDelay: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class TESConditionItem;
class TESCondition { public: TESConditionItem* head; };
struct IDLE_DATA { std::int8_t loopMin, loopMax; std::uint8_t flags, animationGroupSelection; std::uint16_t replayDelay; };
// BSFixedString, _data, NiFormArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class NiFormArray;
// Query: GUESS(low)
class BSFixedString { public: const char* _data; int Query(); };
// TESIdleForm, conditions, data, childIdles, parentIdle, prevIdle, animFileName, animEventName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT) STANDIN
class TESIdleForm : public TESForm { public:
 TESCondition conditions; IDLE_DATA data; NiFormArray* childIdles; TESIdleForm* parentIdle; TESIdleForm* prevIdle; BSFixedString animFileName; BSFixedString animEventName;
 // sub: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) GUESS(low)
 bool sub();
};
