// PlayerCharacterCleanup: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ImageSpaceModifierInstanceDOF, vatsDOFInstance, dynamicDOFInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target identities inferred.
// PlayerCharacterCleanup, ClearVats, ClearDynamic, Release, member windows: STANDIN GUESS(medium); partial view and inferred cleanup contract, no ownership claim.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "PlayerCharacterMembers.h"
namespace P2072 {
class ImageSpaceModifierInstanceDOF { public: void Release(); };
class PlayerCharacterCleanup {
public:
    void ClearVats();
    void ClearDynamic();
    struct DepthOfFieldWindow {
        ImageSpaceModifierInstanceDOF* vatsDOFInstance;
        ImageSpaceModifierInstanceDOF* dynamicDOFInstance;
    };
    using DepthOfFieldBinding = P206Target::PlayerCharacterTargetMembers::DepthOfField;
};
}
