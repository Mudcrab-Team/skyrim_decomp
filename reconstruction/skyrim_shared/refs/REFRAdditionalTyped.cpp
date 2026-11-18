// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// REFRAdditionalTyped: STANDIN GUESS(low); receiver and signatures inferred from accesses.
// ExtraDataList, TESBoundObject, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Record, State, Value, FindRecord, FindState, Resolve, Lookup, GetA, GetB, Read, DefaultValue, Function2e6a40, Function2f6310, Function301130, Function3010a0, Function3010e0: GUESS(low); inferred from target accesses and calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x301130 P2062::REFRAdditionalTyped::Function301130
// 0x3010a0 P2062::REFRAdditionalTyped::Function3010a0
// 0x3010e0 P2062::REFRAdditionalTyped::Function3010e0

#include "REFRAdditionalTyped.h"
namespace P2062 {
Value* REFRAdditionalTyped::Function301130() { auto p=extraList.FindState(); return p ? ReadRecord(p) : &OtherDefaultValue; }
Value* REFRAdditionalTyped::Function3010a0() { auto p=Lookup(extraList.Resolve()); return p ? p->GetA() : &DefaultValue; }
Value* REFRAdditionalTyped::Function3010e0() { auto p=Lookup(extraList.Resolve()); return p ? p->GetB() : &DefaultValue; }
}
