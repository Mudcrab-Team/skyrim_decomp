// Actor: GUESS(low) STANDIN
/*
 * Actor: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x6b1560 20 bytes; RVA 0x6c8a60 20 bytes; RVA 0xa0d530 20 bytes; RVA 0x6a6940 21 bytes; RVA 0x6a69a0 21 bytes; RVA 0x6a69e0 21 bytes; RVA 0x6a6bc0 21 bytes; RVA 0x6a5b30 30 bytes; RVA 0x6a5b60 30 bytes; RVA 0x6a5b90 30 bytes; RVA 0x6a6ff0 30 bytes; RVA 0x6d3d30 31 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Types adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Stand-ins are unverified.
 */
#include "Actor_6a5b30.h"
bool Actor::Function6c8a60() { return StateCode() == 9; }
void Actor::Forward6a6940() { return Subobject()->Call791800(); }
void Actor::Forward6a69a0() { return Subobject()->Call791cb0(); }
void Actor::Forward6a69e0() { return Subobject()->Call791750(); }
void Actor::Forward6a6bc0() { return Subobject()->Call790a90(); }
void Actor::Forward6a5b30(void* value) { return Subobject()->Call792510(value); }
void Actor::Forward6a5b60(void* value) { return Subobject()->Call7924b0(value); }
void Actor::Forward6a5b90(void* value) { return Subobject()->Call792570(value); }
void Actor::Forward6a6ff0(void* value) { return Subobject()->Call791e60(value); }
std::uint32_t papyrus::Actor::LevelValue(void*, void*, ::Actor* actor) { return actor->LevelValue(); }
void* Actor::Forward6d3d30() { auto* related = Related(); return related ? related->Call237e10() : nullptr; }

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

const BSFixedString& Actor::GetResponseString() const { return FixedStrings::GetSingleton()->actorResponse; }
