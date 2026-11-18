// SceneActor: STANDIN GUESS(low); incomplete target-bound view; original identity and ownership unproved.
// Origin: original reconstruction with cited adapted declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/actors/ActorPrimaryTargetPrefix.h"
#include <cstdint>
namespace P2071 {
// SceneActor: STANDIN GUESS(medium); partial primary actor receiver.
class SceneActor : public P206Target::ActorPrimaryTargetPrefix { public:
    // UpdateScene: GUESS(low); inferred effect and argument type, return ABI unknown.
    void UpdateScene(std::uint32_t);
};
// ApplyScene: GUESS(low); target callee signature and meaning inferred.
void ApplyScene(P206Target::BGSScene*, SceneActor*, std::uint32_t);
}
