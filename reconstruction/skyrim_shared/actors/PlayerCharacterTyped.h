// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerCharacterTyped: STANDIN GUESS(low); receiver identity is provisional.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2062 {
// PlayerCharacter, AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function677c40, Function6adea0, QueryOne, QueryTwo: GUESS(low); owner and signatures are unbound.
class AIProcess { public: bool QueryOne(); bool QueryTwo(); };
class PlayerCharacterTyped : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, AIProcess> { public: bool Function677c40(); bool Function6adea0(); };
}
