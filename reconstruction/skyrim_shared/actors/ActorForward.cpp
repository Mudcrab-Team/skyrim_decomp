// Source exposure: mixed; Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; types adapted from pinned public MIT declarations.
// ActorForward: STANDIN GUESS(medium); partial research declaration, not a recovered original name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6a6b20 P207SolRetry::ActorForward::ForwardValues
#include "ActorForward.h"
namespace P207SolRetry {
void ActorForward::ForwardValues(const NiPoint3& point, float a, float b, float c) {
    ResolveController()->Forward(point, a, b, c);
}
}
