// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFaceGenKeyframeMultiple, BSFaceGenKeyframeMultiple::Unk_08, BSFaceGenKeyframeMultiple::Unk_0E, values, count: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); unkNN are slot placeholders
// bhkSPCollisionObject::AsLinesGeom: CRASHLOGGER_PDB(59818@2026.10.24); a placeholder name for this slot, not evidence
#pragma once

#include <cstdint>
#include <cstddef>

class BSFaceGenKeyframeMultiple
{
public:
    virtual ~BSFaceGenKeyframeMultiple();  // 00
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual float Unk_08();  // compared: 0x431d20
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual bool Unk_0E(std::uint32_t a_index);  // 70

    std::uint64_t pad08;
    float* values;  // 10
    std::uint32_t count;  // 18
};
