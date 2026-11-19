// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xef3ea0 NiTexture::~NiTexture
// 0xf05940 NiTexture::Unk_25
// NiTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiTexture::~NiTexture, NiTexture::Unk_25: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot01 through Slot24: GUESS(low); placeholder virtual slots that keep Unk_25 at slot 0x25
// pad08 through pad38: GUESS(low); unexamined 8-byte members that bring the object to the 0x40 bytes the image frees
#pragma once

#include <cstdint>

class NiTexture
{
public:
    NiTexture();
    virtual ~NiTexture();  // 00
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void* Unk_25();  // 25, returns null

    std::uint64_t pad08;
    std::uint64_t pad10;
    std::uint64_t pad18;
    std::uint64_t pad20;
    std::uint64_t pad28;
    std::uint64_t pad30;
    std::uint64_t pad38;
};
