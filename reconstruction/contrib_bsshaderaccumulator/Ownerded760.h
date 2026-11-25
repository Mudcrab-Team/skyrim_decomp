// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout. Stamped as a twin of matched 0x151e2e0 (contrib_bsshaderaccumulator/BSShaderAccumulator): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiAccumulator::StartAccumulating: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCamera: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declaration only
// Ownerded760: GUESS(low) STANDIN
// NiAccumulator: GUESS(low) STANDIN
#pragma once
#include "BSShaderAccumulator.h"

class Ownerded760 : public NiAccumulator
{
public:
    void StartAccumulating(NiCamera* a_camera) override;
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void FinishAccumulatingPostResolveDepth(std::uint32_t flags);  // 2B, compared: 0x151ef00
    void PrepareDepth();

    std::uint64_t pad18;
    std::uint64_t pad20;
    std::uint64_t pad28;
    std::uint64_t pad30;
    std::uint64_t pad38;
    std::uint64_t pad40;
    std::uint64_t pad48;
    std::uint64_t pad50;
    std::uint64_t pad58;
    std::uint64_t pad60;
    std::uint64_t pad68;
    std::uint64_t pad70;
    std::uint64_t pad78;
    std::uint64_t pad80;
    std::uint64_t pad88;
    std::uint64_t pad90;
    std::uint64_t pad98;
    std::uint64_t padA0;
    std::uint64_t padA8;
    std::uint64_t padB0;
    std::uint64_t padB8;
    std::uint64_t padC0;
    std::uint64_t padC8;
    std::uint64_t padD0;
    std::uint64_t padD8;
    std::uint64_t padE0;
    std::uint64_t padE8;
    std::uint64_t padF0;
    std::uint64_t padF8;
    std::uint64_t pad100;
    std::uint64_t pad108;
    std::uint64_t pad110;
    std::uint64_t pad118;
    std::uint64_t pad120;
    std::uint64_t pad128;
    std::uint64_t pad130;
    std::uint64_t pad138;
    std::uint64_t pad140;
    std::uint64_t pad148;
    std::uint32_t unk150;  // 150
};
static_assert(offsetof(Ownerded760, unk150) == 0x150, "unk150 offset");
