// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiColorInterpolator, NiColorA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ColorValue, InterpolatorBase, data, count, unk08: GUESS(low)
#pragma once
struct NiColorA { float red, green, blue, alpha; };
struct ColorValue {
    NiColorA value;
    ColorValue(NiColorA input) : value(input) {}
};
class InterpolatorBase {
public:
    InterpolatorBase();
    virtual void unk08();
    char padding[16];
};
class NiColorInterpolator : public InterpolatorBase {
public:
    NiColorInterpolator(NiColorA input);
    ColorValue value;
    void* data;
    unsigned int count;
};
