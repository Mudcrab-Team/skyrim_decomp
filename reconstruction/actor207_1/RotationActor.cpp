// RotationActor: STANDIN GUESS(low); incomplete target-bound view; original identity and ownership unproved.
// Origin: original reconstruction with cited adapted declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x674210 P2071::RotationActor::ModifyRotationZ
#include "RotationActor.h"
namespace P2071 {
void RotationActor::ModifyRotationZ(float amount) {
    SetRotationZ(GetHeading(false) + amount);
}
}
