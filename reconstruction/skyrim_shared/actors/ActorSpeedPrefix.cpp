// ActorSpeedPrefix: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; target packs and pinned community headers as recorded in declaration-evidence.json.
// 0x6a7ce0 P2071::ActorSpeedPrefix::UpdateFastWalkCache
// 0x6a7d30 P2071::ActorSpeedPrefix::UpdateJogCache
// 0x6a7d80 P2071::ActorSpeedPrefix::UpdateRunCache
#include "ActorSpeedPrefix.h"
namespace P2071 {
void ActorSpeedPrefix::UpdateFastWalkCache() {
    float speed = GetFastWalkSpeed();
    auto* process = currentProcess;
    if (process && process->cachedValues) {
        process->cachedValues->cachedFastWalkSpeed = speed;
        process->cachedValues->flags |= 0x400;
    }
}
void ActorSpeedPrefix::UpdateJogCache() {
    float speed = GetJogSpeed();
    auto* process = currentProcess;
    if (process && process->cachedValues) {
        process->cachedValues->cachedJogSpeed = speed;
        process->cachedValues->flags |= 0x800;
    }
}
void ActorSpeedPrefix::UpdateRunCache() {
    float speed = GetRunSpeed();
    auto* process = currentProcess;
    if (process && process->cachedValues) {
        process->cachedValues->cachedRunSpeed = speed;
        process->cachedValues->flags |= 0x2000;
    }
}
}
