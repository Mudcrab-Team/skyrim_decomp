// Source exposure: mixed; Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; types adapted from pinned public MIT declarations.
// ActorVector: STANDIN GUESS(medium); partial research declaration, not a recovered original name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6a7050 P207SolRetry::ActorVector::ReadVector
#include "ActorVector.h"
namespace P207SolRetry {
NiPoint3 ActorVector::ReadVector() {
    // Resolution releases temporary actor references and can invoke their cleanup.
    // Finish that observable work before reading the shared vector snapshot.
    ResolveController();
    return NiPoint3(VectorX, VectorY, VectorZ);
}
}
