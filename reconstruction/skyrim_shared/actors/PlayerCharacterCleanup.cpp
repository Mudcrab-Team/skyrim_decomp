// PlayerCharacterCleanup: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ImageSpaceModifierInstanceDOF, vatsDOFInstance, dynamicDOFInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target identities inferred.
// PlayerCharacterCleanup, ClearVats, ClearDynamic, Release, member windows: STANDIN GUESS(medium); partial view and inferred cleanup contract, no ownership claim.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x778b30 ClearVats
// 0x778b70 ClearDynamic
#include "PlayerCharacterCleanup.h"
namespace P2072 {
void PlayerCharacterCleanup::ClearVats() {
    auto& members = PlayerCharacterMembers::Get<DepthOfFieldWindow, DepthOfFieldBinding>(this);
    if (members.vatsDOFInstance) {
        members.vatsDOFInstance->Release();
        members.vatsDOFInstance = nullptr;
    }
}
void PlayerCharacterCleanup::ClearDynamic() {
    auto& members = PlayerCharacterMembers::Get<DepthOfFieldWindow, DepthOfFieldBinding>(this);
    if (members.dynamicDOFInstance) {
        members.dynamicDOFInstance->Release();
        members.dynamicDOFInstance = nullptr;
    }
}
}
