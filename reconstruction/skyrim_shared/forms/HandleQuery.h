// HandleQuery: STANDIN GUESS(low); receiver and helper identities are provisional.
// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2061 {
// HandleQuery, supporting interfaces: STANDIN GUESS(low); names and ABI are provisional.
class HandleQuery;
struct ProcessQuery { void Query(std::uint32_t*); }; extern std::uint32_t invalidHandle;
class HandleQuery : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, ProcessQuery> { public: std::uint32_t* Function69c120(std::uint32_t*); };
}
