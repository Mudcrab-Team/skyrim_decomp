// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// REFRAdditionalTyped: STANDIN GUESS(low); receiver and signatures inferred from accesses.
// ExtraDataList, TESBoundObject, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Record, State, Value, FindRecord, FindState, Resolve, Lookup, GetA, GetB, Read, DefaultValue, Function2e6a40, Function2f6310, Function301130, Function3010a0, Function3010e0: GUESS(low); inferred from target accesses and calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2062 {
struct Value;
struct Record { std::uint64_t unknown0; Value* value; };
struct StateAdditional { Value* GetA(); Value* GetB(); };
struct ExtraListAdditional : P206Target::ExtraDataListPrefix {
  void* FindRecord(); Record* FindState(); void* Resolve();
};
struct TESBoundObject { std::uint8_t unknown0[0x1a]; std::uint8_t formType; };
class REFRAdditionalTyped : public P206Target::ReferencePrefix<ExtraListAdditional> {
public:
 
  void* Function2f6310();
  Value* Function301130();
  Value* Function3010a0();
  Value* Function3010e0();
  void* FindObject();
};
void* Read(void*);
StateAdditional* Lookup(void*);
Value* ReadRecord(Record*);
extern Value DefaultValue;
extern Value OtherDefaultValue;
}
