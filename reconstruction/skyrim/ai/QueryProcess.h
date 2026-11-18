// QueryProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed. Drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/actors/ActorTargetPrefix.h"
#include <cstdint>
namespace P2071 {
// QueryProcess: STANDIN GUESS(low); no complete process layout asserted.
class QueryProcess { public:
    // QueryFlag: GUESS(low); direct callee contract inferred from its caller.
    void QueryFlag(std::uint32_t*);
};
// QueryActor: STANDIN GUESS(low); receiver identity unconfirmed.
using QueryActor = P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, QueryProcess>;
// QueryProcessFlag15, QueryProcessFlag1: GUESS(low); names encode only input values.
bool QueryProcessFlag15(QueryActor*);
bool QueryProcessFlag1(QueryActor*);
}
