// PackageProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x674920 P2071::HasPackageType29
// 0xa00e20 P2071::ScriptIsAlarmed
#include "PackageProcess.h"
namespace P2071 {
bool HasPackageType29(PackageActor* actor) {
    bool result = false;
    if (actor->currentProcess) {
        auto* package = actor->currentProcess->RunningPackage();
        if (package && package->packType == 29) result = true;
    }
    return result;
}
bool ScriptIsAlarmed(void*, unsigned, PackageActor* actor) {
    return FindPackage(actor) && FindPackage(actor)->packType == 21;
}
}
