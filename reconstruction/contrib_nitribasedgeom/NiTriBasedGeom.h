// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf18520 NiTriBasedGeom::AsNiTriBasedGeom
// 0xf1f3f0 NiTriBasedGeom::Unk_36
// 0xf1f480 NiTriBasedGeom::~NiTriBasedGeom
// NiTriBasedGeom: EXE_RTTI
// NiObject, NiGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::AsNiTriBasedGeom, NiGeometry::Unk_36: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the image overrides both in NiTriBasedGeom, NG declares Unk_36 as void
// NiTriBasedGeom::~NiTriBasedGeom, NiGeometry::~NiGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the image calls the base complete destructor from the deleting one
// NiGeometryData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiGeometryData::Unk_2B: GUESS(low); the slot the compared code calls through the pointer at 0x120, returning a 16-bit value
// NiGeometry::geometryData: GUESS(low); the pointer the compared code reads at 0x120
// Slot00 through Slot0D, Slot0F through Slot35 (NiObject and NiGeometry): GUESS(low); placeholder virtual slots that keep the named slots at the vtable offsets the image encodes
// pad08 through pad118, pad128, pad130: GUESS(low); unexamined 8-byte members that keep geometryData at 0x120 and bring the object to the 0x138 bytes the image frees
#pragma once

#include <cstdint>

class NiGeometryData
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
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual std::uint16_t Unk_2B();  // 2B
};

class NiTriBasedGeom;

class NiObject
{
public:
    virtual ~NiObject();  // 00
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
    virtual NiTriBasedGeom* AsNiTriBasedGeom();  // 0E
};

class NiGeometry : public NiObject
{
public:
    NiGeometry();
    ~NiGeometry() override;  // 00
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
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual std::uint32_t Unk_36();  // 36

    std::uint64_t pad08;
    std::uint64_t pad10;
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
    NiGeometryData* geometryData;  // 120
};

class NiTriBasedGeom : public NiGeometry
{
public:
    NiTriBasedGeom();
    ~NiTriBasedGeom() override;  // 00, compared: 0xf1f480
    NiTriBasedGeom* AsNiTriBasedGeom() override;  // 0E, compared: 0xf18520
    std::uint32_t Unk_36() override;  // 36, compared: 0xf1f3f0

    std::uint64_t pad128;  // 128
    std::uint64_t pad130;  // 130
};
