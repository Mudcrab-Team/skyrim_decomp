// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ActorGraphFlags, GraphHolder, KeyTable, GraphKey, GetKeyTable, SetBool, Function673cc0, Function6aec10: STANDIN GUESS(low); inferred from receiver offsets and target calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2062 {
struct GraphKey { const char* data; };
struct KeyTable { std::uint64_t unknown0[0x6b]; GraphKey sprint; std::uint64_t unknown360[12]; GraphKey injured; };
class GraphHolder { public: void SetBool(const GraphKey&, bool); };
KeyTable* GetKeyTable();
class ActorGraphFlags : public P206Target::ActorTargetPrefix<> { public: void Function673cc0(bool); void Function6aec10(bool); };
}
