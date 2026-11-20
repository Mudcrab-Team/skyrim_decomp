// Blocking: STANDIN GUESS(low); receiver and helper identities are provisional.
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction, community declarations as noted.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2061 {
// Blocking, supporting interfaces: STANDIN GUESS(low); names and ABI are provisional.
class Blocking;
struct GraphVtable { void* unknown00[18]; void (*GetBoolean)(void*, const void*, bool*); }; struct Graph { GraphVtable* vtable; }; struct GraphNames { std::uint8_t unknown00[0x2b8]; std::uint64_t blocking; }; GraphNames* GetGraphNames();
class Blocking : public P206Target::ActorTargetPrefix<> { public: bool IsBlocking(); };
}
