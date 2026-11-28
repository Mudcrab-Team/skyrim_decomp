// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: implementation based on the pinned game build; see Adapted bodies.
// Adapted bodies: NiBinaryStreamfa6e60::Write4, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// NiPSysBombModifier, NiPSysBombModifier::SaveBinary_140D0FA60: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStreamfa6e60, NiStreamfa6e60, NiPoint3fa6e60, NiPSysModifierfa6e60, NiAVObjectfa6e60, WriteCallback, SaveLinkID, SaveBinary, bombObj, bombAxis, decay, deltaV, decayType, symmType, ostr, bytesWritten, writeFn: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiBinaryStreamfa6e60;
using WriteCallback = std::uint32_t (*)(NiBinaryStreamfa6e60*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

class NiBinaryStreamfa6e60
{
public:
    void Write4(const void* a_data)
    {
        std::uint32_t size = 4;
        bytesWritten += writeFn(this, a_data, 4, &size, 1);
    }

    std::uint8_t  unk00[0x08];  // 00
    std::uint32_t bytesWritten; // 08
    std::uint8_t  unk0C[0x0C];  // 0C
    WriteCallback writeFn;      // 18
};
static_assert(offsetof(NiBinaryStreamfa6e60, bytesWritten) == 0x08, "bytesWritten offset");
static_assert(offsetof(NiBinaryStreamfa6e60, writeFn) == 0x18, "writeFn offset");

class NiAVObjectfa6e60;

class NiStreamfa6e60
{
public:
    virtual ~NiStreamfa6e60();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B();
    virtual void SaveLinkID(const NiAVObjectfa6e60* a_obj);  // 0x0C (0x60)

    std::uint8_t          unk08[0x298];  // 008
    NiBinaryStreamfa6e60* ostr;          // 2A0
};
static_assert(offsetof(NiStreamfa6e60, ostr) == 0x2A0, "ostr offset");

struct NiPoint3fa6e60
{
    void SaveBinary(NiStreamfa6e60& a_stream);

    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3fa6e60) == 0x0C, "NiPoint3fa6e60 size");

class NiPSysModifierfa6e60
{
public:
    void SaveBinary(NiStreamfa6e60& a_stream);

    std::uint8_t unk00[0x30];  // 00
};
static_assert(sizeof(NiPSysModifierfa6e60) == 0x30, "NiPSysModifierfa6e60 size");

class NiPSysBombModifier : public NiPSysModifierfa6e60
{
public:
    void SaveBinary_140D0FA60(NiStreamfa6e60& a_stream);  // compared: 0xfa6e60

    NiAVObjectfa6e60* bombObj;    // 30
    NiPoint3fa6e60    bombAxis;   // 38
    float             decay;      // 44
    float             deltaV;     // 48
    std::uint32_t     decayType;  // 4C
    std::uint32_t     symmType;   // 50
};
static_assert(offsetof(NiPSysBombModifier, bombObj) == 0x30, "bombObj offset");
static_assert(offsetof(NiPSysBombModifier, bombAxis) == 0x38, "bombAxis offset");
static_assert(offsetof(NiPSysBombModifier, decay) == 0x44, "decay offset");
static_assert(offsetof(NiPSysBombModifier, symmType) == 0x50, "symmType offset");
