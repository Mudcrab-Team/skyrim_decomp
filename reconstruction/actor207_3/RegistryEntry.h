// RegistryEntry: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by target observations and pinned community declarations where identified.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// RegistryEntry, FindEntry, fallbackValue, ReadIndexedValue, unknownPrefix: STANDIN GUESS(low); lookup result and float field are inferred, original identities unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
namespace P2073 {
class RegistryEntry { public: std::uint8_t unknownPrefix[0x34]; float value; };
RegistryEntry* FindEntry(int index);
extern float fallbackValue;
float ReadIndexedValue();
}
