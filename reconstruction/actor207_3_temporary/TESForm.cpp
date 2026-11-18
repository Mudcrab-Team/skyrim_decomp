// TESForm: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESForm, formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FormManager, PrepareTemporary, RemoveForm, globalManager, SetTemporary, unknownPrefix: STANDIN GUESS(medium); operations and manager identity inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1e6260 SetTemporary
#include "TESForm.h"
namespace P2073 {
void TESForm::SetTemporary() {
    PrepareTemporary(false);
    if (globalManager) globalManager->RemoveForm(this);
    formFlags |= 0x4000;
}
}
