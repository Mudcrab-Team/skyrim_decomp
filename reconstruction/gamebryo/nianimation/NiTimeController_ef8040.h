// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Write as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:25
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStream, NiStream, NiRefObject, NiObject, NiObjectNET, NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::SaveBinary, NiTimeController::SaveBinary, NiTimeController::flags, NiTimeController::frequency: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream::WriteFn, NiBinaryStream::Write, NiBinaryStream::absoluteCurrentPos, NiBinaryStream::unk0C, NiBinaryStream::readFn, NiBinaryStream::writeFn, NiStream::Unk_00, NiStream::Unk_01, NiStream::Unk_02, NiStream::Unk_03, NiStream::Unk_04, NiStream::Unk_05, NiStream::Unk_06, NiStream::Unk_07, NiStream::Unk_08, NiStream::Unk_09, NiStream::Unk_0A, NiStream::Unk_0B, NiStream::SaveLinkID, NiStream::unk08, NiStream::oStr, NiRefObject::Unk_00, NiRefObject::Unk_01, NiRefObject::unk08, NiTimeController::Unk_02, NiTimeController::Unk_03, NiTimeController::Unk_04, NiTimeController::Unk_05, NiTimeController::Unk_06, NiTimeController::Unk_07, NiTimeController::Unk_08, NiTimeController::Unk_09, NiTimeController::Unk_0A, NiTimeController::Unk_0B, NiTimeController::Unk_0C, NiTimeController::Unk_0D, NiTimeController::Unk_0E, NiTimeController::Unk_0F, NiTimeController::Unk_10, NiTimeController::Unk_11, NiTimeController::Unk_12, NiTimeController::Unk_13, NiTimeController::Unk_14, NiTimeController::Unk_15, NiTimeController::Unk_16, NiTimeController::Unk_17, NiTimeController::Unk_18, NiTimeController::Unk_19, NiTimeController::Unk_1A, NiTimeController::Unk_1B, NiTimeController::Unk_1C, NiTimeController::Unk_1D, NiTimeController::Unk_1E, NiTimeController::Unk_1F, NiTimeController::Unk_20, NiTimeController::Unk_21, NiTimeController::Unk_22, NiTimeController::Unk_23, NiTimeController::Unk_24, NiTimeController::Unk_25, NiTimeController::Unk_26, NiTimeController::Unk_27, NiTimeController::Unk_28, NiTimeController::Unk_29, NiTimeController::Unk_2A, NiTimeController::Unk_2B, NiTimeController::Unk_2C, NiTimeController::IsStreamable, NiTimeController::unk12, NiTimeController::phase, NiTimeController::loKeyTime, NiTimeController::hiKeyTime, NiTimeController::unk24, NiTimeController::target, NiTimeController::next: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiObject;
class NiObjectNET;

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t(NiBinaryStream* a_this, const void* a_buffer, std::uint32_t a_bytes,
        std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();

    template <class T>
    void Write(const T* a_value)
    {
        std::uint32_t size = sizeof(T);
        absoluteCurrentPos += writeFn(this, a_value, sizeof(T), &size, 1);
    }

    std::uint32_t absoluteCurrentPos;
    std::uint32_t unk0C;
    void* readFn;
    WriteFn* writeFn;
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream size");

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

    std::uint8_t unk08[0x298];
    NiBinaryStream* oStr;
};
static_assert(offsetof(NiStream, oStr) == 0x2A0, "oStr offset");

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
    void SaveBinary(NiStream& a_stream);
};

class NiObjectNET : public NiObject
{
};

class NiTimeController : public NiObject
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
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual bool IsStreamable();

    void SaveBinary(NiStream& a_stream);

    std::uint16_t flags;
    std::uint16_t unk12;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    std::uint8_t unk24[0x14];
    NiObjectNET* target;
    NiTimeController* next;
};
static_assert(offsetof(NiTimeController, flags) == 0x10, "flags offset");
static_assert(offsetof(NiTimeController, target) == 0x38, "target offset");
static_assert(offsetof(NiTimeController, next) == 0x40, "next offset");
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");
