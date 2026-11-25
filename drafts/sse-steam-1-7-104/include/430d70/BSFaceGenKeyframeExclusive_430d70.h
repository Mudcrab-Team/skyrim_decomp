// Code origin: original reconstruction from authorized local binary analysis.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFaceGenKeyframeExclusive, BSFaceGenKeyframe: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// type, unk0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); inherited keyframe fields
// Unk_01, Unk_02, Unk_03, Unk_04, Unk_05, Unk_06, Unk_07, Unk_08, Unk_09, Unk_0A, Unk_0B, Unk_0C, Unk_0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_0E, Unk_10: GUESS(low); unused virtual slots
// Reset, Invalidate, SetWeight: GUESS(low); inferred reset operations
// 0x430d70 BSFaceGenKeyframeExclusive::Reset

#pragma once
#include <cstdint>

class BSFaceGenKeyframe {
public:
    virtual ~BSFaceGenKeyframe();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    std::uint32_t type;
    float unk0C;
};
class BSFaceGenKeyframeExclusive : public BSFaceGenKeyframe {
public:
    virtual void Unk_0E();
    virtual void Invalidate(signed char index);
    virtual void Unk_10();
    virtual void SetWeight(float value);
    void Reset();
};
