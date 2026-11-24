// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiGeometry, NiGeometry::ForwardToAttachedObjects, NiGeometryAttachment, unk26, pad08, field18, skin, attached: GUESS(low)
// flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

// Minimal stand-in: an attached object whose virtual slot 0x26 takes the forwarded argument.
class NiGeometryAttachment
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26(void* a_arg);

    std::uint8_t pad08[0x10];
    void* field18;
};

class NiGeometry
{
public:
    void ForwardToAttachedObjects(void* a_arg);  // compared: 0xf0b0d0

    std::uint8_t unk00[0xF4];
    std::uint32_t flags;
    std::uint8_t unkF8[0x18];
    NiGeometryAttachment* attached;
    NiGeometryAttachment* skin;
};
