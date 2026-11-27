// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports BSMultiBound::RegisterStreamables as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niconsolerenderer/niconsolepersistentsrctexturerendererdata_od_variant_ob1_variant.cpp:49
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiRefObject, NiObject, BSMultiBoundShape, BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::RegisterStreamables, BSMultiBound::RegisterStreamables, BSMultiBound::data, BSMultiBound::unk10: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::Unk_00, NiRefObject::Unk_01, NiRefObject::unk08, NiObject::Unk_02, NiObject::Unk_03, NiObject::Unk_04, NiObject::Unk_05, NiObject::Unk_06, NiObject::Unk_07, NiObject::Unk_08, NiObject::Unk_09, NiObject::Unk_0A, NiObject::Unk_0B, NiObject::Unk_0C, NiObject::Unk_0D, NiObject::Unk_0E, NiObject::Unk_0F, NiObject::Unk_10, NiObject::Unk_11, NiObject::Unk_12, NiObject::Unk_13, NiObject::Unk_14, NiObject::Unk_15, NiObject::Unk_16, NiObject::Unk_17, NiObject::Unk_18, NiObject::Unk_19, BSMultiBound::unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiStream;

class NiRefObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();

    std::uint64_t unk08;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
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
    virtual bool RegisterStreamables(NiStream& a_stream);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class BSMultiBoundShape : public NiObject
{
};

class BSMultiBound : public NiObject
{
public:
    bool RegisterStreamables(NiStream& a_stream) override;

    std::uint32_t unk10;
    std::uint32_t unk14;
    BSMultiBoundShape* data;
};
static_assert(offsetof(BSMultiBound, data) == 0x18, "data offset");
static_assert(sizeof(BSMultiBound) == 0x20, "BSMultiBound size");
