// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiControllerSequence, NiControllerSequence::RegisterStreamables_140CC5080: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedStringf54af0, NiStreamf54af0, NiObjectf54af0, InterpArrayItemf54af0, IDTagf54af0, RegisterFixedString, RegisterStreamables, name, arraySize, interpArray, idTags, textKeys, accumRootName, animNotes, animNotesCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSFixedStringf54af0
{
    const char* data;  // 00
};
static_assert(sizeof(BSFixedStringf54af0) == 0x08, "BSFixedStringf54af0 size");

class NiStreamf54af0
{
public:
    virtual ~NiStreamf54af0();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07();
    virtual bool RegisterFixedString(const BSFixedStringf54af0& a_str);  // 08 (0x40)
};

class NiObjectf54af0
{
public:
    virtual ~NiObjectf54af0();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17(); virtual void Unk_18();
    virtual void Unk_19();
    virtual bool RegisterStreamables(NiStreamf54af0& a_stream);  // 1A (0xD0)

    std::uint64_t unk08;  // 08
};
static_assert(sizeof(NiObjectf54af0) == 0x10, "NiObjectf54af0 size");

struct InterpArrayItemf54af0
{
    NiObjectf54af0* interp;      // 00
    NiObjectf54af0* controller;  // 08
    std::uint64_t   unk10;       // 10
    std::uint64_t   unk18;       // 18
};
static_assert(sizeof(InterpArrayItemf54af0) == 0x20, "InterpArrayItemf54af0 size");

struct IDTagf54af0
{
    BSFixedStringf54af0 avObjectName;    // 00
    BSFixedStringf54af0 propertyType;    // 08
    BSFixedStringf54af0 ctlrType;        // 10
    BSFixedStringf54af0 ctlrID;          // 18
    BSFixedStringf54af0 interpolatorID;  // 20
};
static_assert(sizeof(IDTagf54af0) == 0x28, "IDTagf54af0 size");

class NiControllerSequence : public NiObjectf54af0
{
public:
    bool RegisterStreamables_140CC5080(NiStreamf54af0& a_stream);  // compared: 0xf54af0

    BSFixedStringf54af0    name;            // 10
    std::uint32_t          arraySize;       // 18
    std::uint32_t          unk1C;           // 1C
    InterpArrayItemf54af0* interpArray;     // 20
    IDTagf54af0*           idTags;          // 28
    std::uint64_t          unk30;           // 30
    NiObjectf54af0*        textKeys;        // 38
    std::uint8_t           unk40[0x48];     // 40
    BSFixedStringf54af0    accumRootName;   // 88
    std::uint8_t           unk90[0x18];     // 90
    NiObjectf54af0**       animNotes;       // A8
    std::uint16_t          animNotesCount;  // B0
};
static_assert(offsetof(NiControllerSequence, name) == 0x10, "name offset");
static_assert(offsetof(NiControllerSequence, arraySize) == 0x18, "arraySize offset");
static_assert(offsetof(NiControllerSequence, textKeys) == 0x38, "textKeys offset");
static_assert(offsetof(NiControllerSequence, accumRootName) == 0x88, "accumRootName offset");
static_assert(offsetof(NiControllerSequence, animNotes) == 0xA8, "animNotes offset");
static_assert(offsetof(NiControllerSequence, animNotesCount) == 0xB0, "animNotesCount offset");
