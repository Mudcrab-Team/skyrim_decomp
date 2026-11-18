// MagicTarget: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerReceiver, QueryGuard, invulnerabilityOverride: STANDIN GUESS(medium); complete receiver and global identities inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x74a500 IsInvulnerable
#include "MagicTarget_74a500.h"
namespace P2073 {
bool MagicTarget::IsInvulnerable() {
    return invulnerabilityOverride || PlayerReceiver::FromMagicTarget(this)->QueryGuard();
}
}
