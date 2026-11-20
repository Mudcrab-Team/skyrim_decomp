// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// 0x151e2e0 BSShaderAccumulator::StartAccumulating
// 0x151ef00 BSShaderAccumulator::FinishAccumulatingPostResolveDepth
// BSShaderAccumulator, NiAccumulator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSShaderAccumulator::StartAccumulating, BSShaderAccumulator::FinishAccumulatingPostResolveDepth, NiAccumulator::StartAccumulating, NiAccumulator::FinishAccumulating: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiCamera: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declaration only
// BSShaderAccumulator::PrepareDepth: GUESS(low); the helper the compared code calls when the counter is zero
// NiAccumulator::FinishAccumulating: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); NG declares no argument, the image forwards the 32-bit flags in its second register
// NiAccumulator::camera: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); the pointer the compared code stores at 0x10
// BSShaderAccumulator::unk150: GUESS(low); the counter the compared code tests against zero
// Unk_00 through Unk_24, Unk_27 through Unk_2A: GUESS(low); placeholder virtual slots that keep the named slots at slots 0x25, 0x26 and 0x2B
// pad08, pad18 through pad148: GUESS(low); unexamined 8-byte members that keep camera at 0x10 and unk150 at 0x150
#pragma once

#include <cstddef>
#include <cstdint>

class NiCamera;

class NiAccumulator
{
public:
    virtual void Unk_00();
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
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void StartAccumulating(NiCamera* a_camera);  // 25
    virtual void FinishAccumulating(std::uint32_t a_flags);  // 26, base implementation

    std::uint64_t pad08;  // 08
    NiCamera*     camera;  // 10
};

class BSShaderAccumulator : public NiAccumulator
{
public:
    void StartAccumulating(NiCamera* a_camera) override;  // compared: 0x151e2e0
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

static_assert(offsetof(BSShaderAccumulator, unk150) == 0x150, "unk150 offset");
