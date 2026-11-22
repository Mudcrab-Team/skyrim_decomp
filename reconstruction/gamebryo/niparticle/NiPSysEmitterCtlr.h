// Source exposure: mixed (local binary analysis and public names).
// 0xff4f40 compared function
// 0xfa0950 compared function
// 0xf9b800 compared function
// 0xf9aad0 compared function
// 0xf9a8d0 compared function
// Code origin: original; the two bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiPSysEmitterCtlr: EXE_RTTI
// GetInterpolatorCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Functionf62de0, Functioneb11e0, interpolator0, interpolator1, field50: GUESS(low)
#pragma once
#include <cstdint>

class NiStream;

// NiStream: STANDIN GUESS(low); only the virtual slot at 0x60 used by SaveBinary is claimed.
class NiStream
{
public:
    virtual ~NiStream();
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
    virtual void WritePointer(void* a_value);
};

class NiPSysEmitterCtlr;
void Functionf62de0(NiPSysEmitterCtlr* a_source, NiPSysEmitterCtlr* a_destination);
void Functioneb11e0(void* a_destination, void* a_source);
void Functionfa0a00(NiPSysEmitterCtlr* a_source, NiStream* a_stream);
void Functionf9a3f0(NiPSysEmitterCtlr* a_source, NiPSysEmitterCtlr* a_destination);
void Functionef7340(NiPSysEmitterCtlr* a_source);

class NiPSysEmitterCtlr
{
public:
    virtual std::uint32_t GetInterpolatorCount() const;
    void* GetInterpolator(std::uint16_t a_index) const;
    void Functionfa0950(NiPSysEmitterCtlr* a_other);
    void SaveBinary(NiStream* a_stream);
    void Stop();
    void Functionff4f40(NiPSysEmitterCtlr* a_other);

    std::uint8_t pad08[0x40];  // 08
    void*        interpolator0;  // 48
    std::uint8_t field50[0x10];  // 50
    void*        interpolator1;  // 60
    std::uint8_t pad68[8];  // 68
    std::uint32_t field70;  // 70
    std::uint32_t field74;  // 74
    std::uint8_t pad78[0x20];  // 78
    std::uint16_t field98;  // 98
};
