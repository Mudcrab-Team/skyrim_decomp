// ArrestProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed, target pack and public community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xa00e70 P2071::PapyrusIsArrested
#include "ArrestProcess.h"
namespace P2071 {
bool PapyrusIsArrested(void*, unsigned, ArrestActor* actor) {
    return actor->currentProcess && actor->currentProcess->IsArrested();
}
}
