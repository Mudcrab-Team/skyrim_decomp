// Code origin: bodies written for this unit from the listings of the pinned image; names and
// declarations from CommonLibSSE-NG, and the Ctor name from powerof3/CommonLibSSE. No community or sibling body is adapted.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image). Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// Adapted bodies: none
// 0xefe1f0 NiPointLight::LoadBinary
// 0xefe2e0 NiPointLight::SaveBinary
// 0xefe3b0 NiPointLight::IsEqual
// 0xefe4e0 NiPointLight::Ctor
// 0xefe5f0 NiPointLight::~NiPointLight
#include "NiPointLight.h"

#include <new>

// StreamRead, StreamWrite: GUESS(low); one raw read or write of a member through the stream's
// function pointer, advancing the stream position by the bytes moved.
template <class T>
static inline bool StreamRead(NiBinaryStream* a_in, T* a_value, std::uint32_t a_count)
{
    std::uint32_t size = sizeof(T);
    std::uint32_t toRead = a_count * size;
    std::uint32_t bytesRead = a_in->_readFn(a_in, a_value, toRead, &size, 1);
    a_in->_absoluteCurrentPos += bytesRead;
    return bytesRead == toRead;
}

template <class T>
static inline bool StreamWrite(NiBinaryStream* a_out, const T* a_value, std::uint32_t a_count)
{
    std::uint32_t size = sizeof(T);
    std::uint32_t toWrite = a_count * size;
    std::uint32_t bytesWritten = a_out->_writeFn(a_out, a_value, toWrite, &size, 1);
    a_out->_absoluteCurrentPos += bytesWritten;
    return bytesWritten == toWrite;
}

// RVA 0xefe1f0, 192 bytes.
void NiPointLight::LoadBinary(NiStream& a_stream)
{
    NiLight::LoadBinary(a_stream);
    StreamRead(a_stream.iStr, &constAttenuation, 1);
    StreamRead(a_stream.iStr, &linearAttenuation, 1);
    StreamRead(a_stream.iStr, &quadraticAttenuation, 1);
}

// RVA 0xefe2e0, 192 bytes.
void NiPointLight::SaveBinary(NiStream& a_stream)
{
    NiLight::SaveBinary(a_stream);
    StreamWrite(a_stream.oStr, &constAttenuation, 1);
    StreamWrite(a_stream.oStr, &linearAttenuation, 1);
    StreamWrite(a_stream.oStr, &quadraticAttenuation, 1);
}

// RVA 0xefe3b0, 102 bytes.
bool NiPointLight::IsEqual(NiObject* a_object)
{
    if (!NiLight::IsEqual(a_object)) {
        return false;
    }
    NiPointLight* other = static_cast<NiPointLight*>(a_object);
    if (constAttenuation != other->constAttenuation) {
        return false;
    }
    if (linearAttenuation != other->linearAttenuation) {
        return false;
    }
    if (quadraticAttenuation != other->quadraticAttenuation) {
        return false;
    }
    return true;
}

// Not compared on its own: inlined into Ctor below. Defining it also makes the compiler emit the
// vftable and, beside it, the scalar deleting destructor compared at RVA 0xefe5f0.
NiPointLight::NiPointLight() :
    constAttenuation(0.0f),
    linearAttenuation(1.0f),
    quadraticAttenuation(0.0f)
{
}

// RVA 0xefe4e0, 52 bytes: constructs the light in place.
NiPointLight* NiPointLight::Ctor()
{
    return new (this) NiPointLight;
}
