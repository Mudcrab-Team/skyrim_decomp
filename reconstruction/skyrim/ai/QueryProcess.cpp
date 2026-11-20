// QueryProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed. Drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x868e80 P2071::QueryProcessFlag15
// 0x868ed0 P2071::QueryProcessFlag1
#include "QueryProcess.h"
namespace P2071 {
bool QueryProcessFlag15(QueryActor* actor) {
    if (!actor || !actor->currentProcess) return false;
    std::uint32_t flags = 15;
    actor->currentProcess->QueryFlag(&flags);
    return ((flags >> 30) & 1) != 0;
}
bool QueryProcessFlag1(QueryActor* actor) {
    if (!actor || !actor->currentProcess) return false;
    std::uint32_t flags = 1;
    actor->currentProcess->QueryFlag(&flags);
    return ((flags >> 30) & 1) != 0;
}
}
