// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original declarations inferred from the pinned listing, with names as labelled below
// Source exposure: binary-analysis
// NiQuaternionInterpolator, NiQuaternion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// QuaternionValue, InterpolatorBase, value, data, count, unk08, padding: GUESS(low)
#pragma once
struct NiQuaternion { float w, x, y, z; };
struct QuaternionValue { NiQuaternion value; QuaternionValue(NiQuaternion input) : value(input) {} };
class InterpolatorBase { public: InterpolatorBase(); virtual void unk08(); char padding[16]; };
class NiQuaternionInterpolator : public InterpolatorBase {
public:
    NiQuaternionInterpolator(NiQuaternion input);
    QuaternionValue value;
    void* data;
    unsigned int count;
};
