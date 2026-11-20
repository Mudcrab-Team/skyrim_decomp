// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)

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
// BSExtraData, next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
// ExtraPackage, unk10, index, target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// stateFlags: GUESS(low)
class TESPackage;
class ExtraPackage : public BSExtraData { public: TESPackage* unk10; std::int32_t index; std::uint32_t target; std::uint8_t stateFlags; };
// TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraLeveledItem, levItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class ExtraLeveledItem : public BSExtraData { public: std::uint32_t levItem; };
// LeveledValueExtraPrefix, value: GUESS(low) STANDIN
// Partial view of this build's observed signed halfword. CommonLib describes a FormID at
// this location; this view makes no claim that its FormID declaration is a halfword.
// No complete object size, allocation layout or field meaning is asserted.
class LeveledValueExtraPrefix : public BSExtraData { public: std::int16_t value; };
// BGSSaveLoadBuffer, BGSLoadGameSubBuffer, buffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BGSSaveLoadBuffer { char* buffer; };
struct BGSLoadGameSubBuffer { BGSSaveLoadBuffer buffer; };
// ExtraSavedAnimation, animationBuffer, ExtraSavedHavokData, havokBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class ExtraSavedAnimation : public BSExtraData { public: BGSLoadGameSubBuffer animationBuffer; };
class ExtraSavedHavokData : public BSExtraData { public: BGSLoadGameSubBuffer havokBuffer; };
// REF_ACTIVATE_DATA, ExtraActivateRefChildren, children, activateChildrenTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SimpleActivationList: GUESS(low) STANDIN
struct REF_ACTIVATE_DATA;
struct SimpleActivationList { REF_ACTIVATE_DATA* item; SimpleActivationList* next; };
class ExtraActivateRefChildren : public BSExtraData { public: SimpleActivationList children; float activateChildrenTimer; };
// ExtraHealthPerc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// healthFraction: GUESS(low)
class ExtraHealthPerc : public BSExtraData { public: float healthFraction; };
// defaultA, emptyBuffer: GUESS(low) STANDIN
extern float defaultA;
extern float defaultB;
extern BGSLoadGameSubBuffer emptyBuffer;
// ExtraDataList, GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function162410, Function164e20, Function16fe90, Function1700c0, Function1690d0, Function169100, Function170c50: GUESS(low)
class ExtraDataList { public:
 BSExtraData* GetByType(std::uint32_t type);
 void Function162410(bool); std::int32_t Function164e20();
 BGSLoadGameSubBuffer* Function16fe90(); BGSLoadGameSubBuffer* Function1700c0();
 void Function1690d0(float); float Function169100(); float Function170c50();
};
