// MagicTarget: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// MagicTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerReceiver, QueryGuard, invulnerabilityOverride: STANDIN GUESS(medium); complete receiver and global identities inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2073 {
class MagicTarget : public P206Target::MagicTargetPrefix {
public:
    bool IsInvulnerable();
};
// reference, magicTarget: STANDIN GUESS(medium); target-bound containing receiver prefix.
class PlayerReceiver {
public:
    P206Target::ReferencePrefix<> reference;
    MagicTarget magicTarget;
    bool QueryGuard();
    static PlayerReceiver* FromMagicTarget(MagicTarget* target) {
        return reinterpret_cast<PlayerReceiver*>(reinterpret_cast<char*>(target) - offsetof(PlayerReceiver, magicTarget));
    }
};
static_assert(offsetof(PlayerReceiver, magicTarget) == 0xa0, "target secondary receiver anchor");
extern bool invulnerabilityOverride;
}
