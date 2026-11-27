// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiStream, BSMultiBoundShape, BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::SaveBinary, BSMultiBound::SaveBinary, BSMultiBound::data, BSMultiBound::unk10: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::unk00, NiStream::Unk_00, NiStream::Unk_01, NiStream::Unk_02, NiStream::Unk_03, NiStream::Unk_04, NiStream::Unk_05, NiStream::Unk_06, NiStream::Unk_07, NiStream::Unk_08, NiStream::Unk_09, NiStream::Unk_0A, NiStream::Unk_0B, NiStream::SaveLinkID, BSMultiBound::unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject;

class NiStream
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
    virtual void SaveLinkID(const NiObject* a_object);
};

class NiRefObject
{
public:
    std::uint8_t unk00[0x10];
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    void SaveBinary(NiStream& a_stream);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class BSMultiBoundShape : public NiObject
{
};

class BSMultiBound : public NiObject
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint32_t unk10;
    std::uint32_t unk14;
    BSMultiBoundShape* data;
};
static_assert(offsetof(BSMultiBound, data) == 0x18, "data offset");
static_assert(sizeof(BSMultiBound) == 0x20, "BSMultiBound size");
