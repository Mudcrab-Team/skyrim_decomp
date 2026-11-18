// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x162410 ExtraDataList::Function162410
// 0x164e20 ExtraDataList::Function164e20
// 0x16fe90 ExtraDataList::Function16fe90
// 0x1700c0 ExtraDataList::Function1700c0
// 0x1690d0 ExtraDataList::Function1690d0
// 0x169100 ExtraDataList::Function169100
// 0x170c50 ExtraDataList::Function170c50

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

#include "ExtraDataList_162410.h"
void ExtraDataList::Function162410(bool value) { auto* x = static_cast<ExtraPackage*>(GetByType(0x19)); if (x) x->stateFlags = (x->stateFlags & 0xfe) | value; }
std::int32_t ExtraDataList::Function164e20() { auto* x = static_cast<LeveledValueExtraPrefix*>(GetByType(0x2e)); return x ? x->value : -1; }
BGSLoadGameSubBuffer* ExtraDataList::Function16fe90() { auto* x = static_cast<ExtraSavedAnimation*>(GetByType(0x41)); return x ? &x->animationBuffer : &emptyBuffer; }
BGSLoadGameSubBuffer* ExtraDataList::Function1700c0() { auto* x = static_cast<ExtraSavedHavokData*>(GetByType(0x3c)); return x ? &x->havokBuffer : &emptyBuffer; }
void ExtraDataList::Function1690d0(float value) { auto* x = static_cast<ExtraActivateRefChildren*>(GetByType(0x53)); if (x) x->activateChildrenTimer = value; }
float ExtraDataList::Function169100() { auto* x = static_cast<ExtraActivateRefChildren*>(GetByType(0x53)); return x ? x->activateChildrenTimer : defaultA; }
float ExtraDataList::Function170c50() { auto* x = static_cast<ExtraHealthPerc*>(GetByType(0x76)); return x ? x->healthFraction : defaultB; }
