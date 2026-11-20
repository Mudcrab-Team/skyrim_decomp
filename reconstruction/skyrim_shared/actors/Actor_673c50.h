/*
 * Labels: v2
 * Build: sse-steam-1-7-104; RVA 0x673c50, 31 bytes.
 * Evidence: findings/ghidra-import.md
 * Origin: Actor::CanFlyHere adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a src/RE/A/Actor.cpp:130 and include/RE/A/Actor.h, include/RE/T/TESObjectREFR.h, include/RE/T/TESWorldSpace.h (MIT).
 * Source exposure: mixed (binary-analysis and community headers/implementation).
 * Drafted by: gpt-6.1-sol
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Only CanFlyHere is compared; callees are declarations. Minimal per-unit interfaces do not represent complete layouts.
 * Ownership and signatures are community hypotheses, not established by a byte match.
 */
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
// Actor, TESObjectREFR, TESWorldSpace, CanFlyHere, GetWorldspace, HasMaxHeightData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, TESObjectREFR, TESWorldSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
class TESWorldSpace { public: bool HasMaxHeightData() const; };
class TESObjectREFR { public: TESWorldSpace* GetWorldspace() const; };
class Actor : public TESObjectREFR { public: bool CanFlyHere() const; };
