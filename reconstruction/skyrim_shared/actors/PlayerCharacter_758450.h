/*
 * PlayerCharacter: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x761440 28 bytes; RVA 0x758450 29 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Function ownership and method signatures remain unverified; class declarations are stand-ins.
 * Types adapted from CharmedBaryon/CommonLibSSE-NG at b93280e832f263dbef44e44cbe2936622a02f91a (MIT); see header notice.
 */
// PlayerCharacter: STANDIN EXE_RTTI
// ModifyAnimationUpdateData, UnlockWord, BSAnimationUpdateData, deltaTime, pad04, unkFunctionPtr, refr, optionalEyePosition, updateFunctor, flags, unk2A, unk2B, unk2C, unk2D, unk2E, unk2F, TESWordOfPower: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// UpdateBase, UnlockBase, SetKnown, NiPoint3, IPostAnimationChannelUpdateFunctor, TESObjectREFR: GUESS(low)
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
class NiPoint3;
class TESObjectREFR;
class IPostAnimationChannelUpdateFunctor;
class TESWordOfPower { public: void SetKnown(bool); };
struct BSAnimationUpdateData {
    float deltaTime;
    std::uint32_t pad04;
    void* unkFunctionPtr;
    TESObjectREFR* refr;
    NiPoint3* optionalEyePosition;
    IPostAnimationChannelUpdateFunctor* updateFunctor;
    std::uint16_t flags;
    bool unk2A, unk2B, unk2C, unk2D, unk2E, unk2F;
};
static_assert(sizeof(BSAnimationUpdateData) == 0x30, "BSAnimationUpdateData size");
class PlayerCharacter {
public:
    void ModifyAnimationUpdateData(BSAnimationUpdateData&);
    void UnlockWord(TESWordOfPower*);
    void UpdateBase(BSAnimationUpdateData&);
    void UnlockBase(TESWordOfPower*);
};
