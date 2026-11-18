// Source exposure: mixed; Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; types adapted from pinned public MIT declarations.
// NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
namespace P207SolRetry {
// P207SolRetry: GUESS(low); namespace isolates private partial declarations.
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class NiPoint3 {
public:
    constexpr NiPoint3(float a_x, float a_y, float a_z) noexcept : x(a_x), y(a_y), z(a_z) {}
    float x, y, z;
};
// MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class MovementControllerNPC {
public:
    // Forward: GUESS(low); direct receiver, point and three scalar argument ABI inferred.
    void Forward(const NiPoint3&, float, float, float);
};
}
