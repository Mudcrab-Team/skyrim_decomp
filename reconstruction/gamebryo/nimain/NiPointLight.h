// Code origin: original contributor declarations from CommonLibSSE-NG names and layouts (the Ctor
// name from powerof3/CommonLibSSE). Review fix by gpt-6.1-sol reuses the represented NiAVObject base from NiAVObject.h and the NiColor value declaration used in small202_b72804af/Sky.h.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// base declarations from existing repository headers and local analysis of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// NiPointLight, NiPointLight::LoadBinary, NiPointLight::~NiPointLight, NiPointLight::SaveBinary, NiPointLight::IsEqual, NiLight::~NiLight, NiLight::LoadBinary, NiLight::SaveBinary, NiLight::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiAVObject.h"

#include <cstdint>
#include <cstddef>

// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the compared code reads
class NiBinaryStream
{
public:
    // ReadFn, WriteFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    using ReadFn = std::uint32_t(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);
    using WriteFn = std::uint32_t(NiBinaryStream* a_this, const void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);

    virtual ~NiBinaryStream();  // 00

    // _absoluteCurrentPos, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint32_t _absoluteCurrentPos;  // 08
    // pad0C: GUESS(low)
    std::uint32_t pad0C;  // 0C
    ReadFn* _readFn;  // 10
    WriteFn* _writeFn;  // 18
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream size");

// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a prefix view up to the two stream pointers
class NiStream
{
public:
    // unk000: GUESS(low); members not used here
    std::uint8_t unk000[0x298];  // 000
    // iStr, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    NiBinaryStream* iStr;  // 298
    NiBinaryStream* oStr;  // 2A0
};

// NiColor, red, green, blue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT);
// represented value declaration reused from reconstruction/small202_b72804af/Sky.h.
struct NiColor
{
    float red;
    float green;
    float blue;
};
static_assert(sizeof(NiColor) == 0x0C, "NiColor size");

// NiLight: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED;
// the pinned image constructor calls the NiAVObject constructor directly.
class NiLight : public NiAVObject
{
public:
    // NiLight::NiLight: GUESS(low); the base constructor the compared constructor calls, declared only, bound by address
    NiLight();
    // NiLight::~NiLight: declared only
    ~NiLight() override;
    // LoadBinary, SaveBinary, IsEqual: declared only; the compared overrides call them directly, bound by address
    void LoadBinary(NiStream& a_stream) override;
    void SaveBinary(NiStream& a_stream) override;
    bool IsEqual(NiObject* a_object) override;

    // color110, color11C, color128: GUESS(medium); three RGB values streamed in order.
    NiColor color110;  // 110
    NiColor color11C;  // 11C
    NiColor color128;  // 128
    // dimmer: GUESS(medium); scalar streamed before the colors, initialized to one.
    float dimmer;  // 134
    // unk138: GUESS(low); constructor clears this 64-bit member; purpose unknown.
    std::uint64_t unk138;  // 138
};
static_assert(sizeof(NiLight) == 0x140, "NiLight size");
static_assert(offsetof(NiLight, color110) == 0x110, "NiLight first color offset");
static_assert(offsetof(NiLight, color11C) == 0x11C, "NiLight second color offset");
static_assert(offsetof(NiLight, color128) == 0x128, "NiLight third color offset");
static_assert(offsetof(NiLight, dimmer) == 0x134, "NiLight scalar offset");
static_assert(offsetof(NiLight, unk138) == 0x138, "NiLight unknown member offset");

class NiPointLight : public NiLight
{
public:
    // NiPointLight::NiPointLight: GUESS(low); not compared on its own, inlined into Ctor
    NiPointLight();
    // NiPointLight::Ctor: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); constructs in place
    NiPointLight* Ctor();  // compared: 0xefe4e0
    // the complete destructor ??1NiPointLight: GUESS(low); declared only, bound by address to the
    // destructor the listing calls
    ~NiPointLight() override;  // compared: 0xefe5f0 (scalar deleting destructor)
    void LoadBinary(NiStream& a_stream) override;  // compared: 0xefe1f0
    void SaveBinary(NiStream& a_stream) override;  // compared: 0xefe2e0
    bool IsEqual(NiObject* a_object) override;  // compared: 0xefe3b0

    // constAttenuation, linearAttenuation, quadraticAttenuation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    float constAttenuation;  // 140
    float linearAttenuation;  // 144
    float quadraticAttenuation;  // 148
    // unk14C: GUESS(low); padding up to the 0x150 size
    std::uint32_t unk14C;  // 14C
};
static_assert(sizeof(NiPointLight) == 0x150, "NiPointLight size");
static_assert(offsetof(NiPointLight, constAttenuation) == 0x140, "constant attenuation offset");
static_assert(offsetof(NiPointLight, linearAttenuation) == 0x144, "linear attenuation offset");
static_assert(offsetof(NiPointLight, quadraticAttenuation) == 0x148, "quadratic attenuation offset");
