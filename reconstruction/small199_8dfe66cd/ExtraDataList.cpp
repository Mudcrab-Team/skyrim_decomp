// Inferred names: GUESS(low)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: GUESS(low)
// 0x163960 ExtraDataList::Function163960
// 0x1693b0 ExtraDataList::Function1693b0
// 0x16e440 ExtraDataList::Function16e440
// 0x171e60 ExtraDataList::Function171e60
// 0x1648c0 ExtraDataList::GetTemper
// 0x164920 ExtraDataList::Function164920
// 0x164950 ExtraDataList::GetCharge
// 0x1649b0 ExtraDataList::Function1649b0
// 0x1649e0 ExtraDataList::Function1649e0
// 0x164a10 ExtraDataList::Function164a10
// 0x170dc0 ExtraDataList::Function170dc0
// 0x171cf0 ExtraDataList::Function171cf0

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

#include "ExtraDataList.h"

std::uint8_t ExtraDataList::Function163960() { auto* extra = static_cast<ExtraHotkey*>(GetByType(73)); return extra ? extra->hotkey : 0xff; }
std::uint32_t ExtraDataList::Function1693b0() { auto* extra = static_cast<ExtraLevCreaModifier*>(GetByType(30)); return extra ? extra->modifier : 4; }
float ExtraDataList::Function16e440() { auto* extra = static_cast<ExtraNorthRotation*>(GetByType(66)); return extra ? extra->northRot : 0.0f; }
float ExtraDataList::Function171e60() { auto* extra = static_cast<ExtraFavorCost*>(GetByType(151)); return extra ? extra->cost : 0.0f; }
float ExtraDataList::GetTemper() { auto* extra = static_cast<ExtraHealth*>(GetByType(37)); return extra ? extra->health : defaultA; }
float ExtraDataList::Function164920() { auto* extra = static_cast<ExtraTimeLeft*>(GetByType(39)); return extra ? extra->time : defaultA; }
float ExtraDataList::GetCharge() { auto* extra = static_cast<ExtraCharge*>(GetByType(40)); return extra ? extra->charge : defaultA; }
float ExtraDataList::Function1649b0() { auto* extra = static_cast<ExtraCachedScale*>(GetByType(176)); return extra ? extra->scale3D : defaultB; }
float ExtraDataList::Function1649e0() { auto* extra = static_cast<ExtraCachedScale*>(GetByType(176)); return extra ? extra->refScale : defaultB; }
float ExtraDataList::Function164a10() { auto* extra = static_cast<ExtraScale*>(GetByType(47)); return extra ? extra->scale : defaultB; }
float ExtraDataList::Function170dc0() { auto* extra = static_cast<ExtraObjectHealth*>(GetByType(85)); return extra ? extra->health : defaultA; }
float ExtraDataList::Function171cf0() { auto* extra = static_cast<ExtraHeadTrackingWeight*>(GetByType(148)); return extra ? extra->weight : defaultB; }
