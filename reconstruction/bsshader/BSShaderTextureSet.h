// Code origin: original; declarations from CommonLibSSE-NG, bodies written from the listing of the pinned image.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderTextureSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTextureSet: STANDIN EXE_RTTI
// BSShaderTextureSet::LoadBinary, BSShaderTextureSet::GetTexturePath, BSShaderTextureSet::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// texturePaths, texturePathStrings: GUESS(low); NG names the member textures and its element count is its Texture::kTotal, the count 9 is the padding that was split off here
// Texture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG nests it in BSTextureSet::Textures
// as std::int32_t, signed here because the target sign-extends the index (MOVSXD)
// BSFixedString, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// _data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the interned string pointer
// _absoluteCurrentPos, _readFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown0C: GUESS(low); the four unread bytes between _absoluteCurrentPos and _readFn
// read: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's template body with binary_read folded in, as the image inlines it
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, unknown108: GUESS(low); unrecovered storage between the vftable, the version fields and iStr, named by its offset and kept only so iStr sits at 0x298 (NG declares a stream header, an object-group array, a file path and pointer arrays over it)
// nifMaxVersion, nifMaxUserDefinedVersion, iStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadFixedStringLegacy: GUESS(low); the callee that fills one path slot, declared only
#pragma once

#include <cstdint>
#include "../gamebryo/nimain/NiObject.h"

enum Texture : std::int32_t
{
};

// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSFixedString
{
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

// NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    // hot path: the engine inlines the read at each use
    template <class CharT>
    bool read(CharT* a_str, std::uint32_t a_count)
    {
        std::uint32_t size = sizeof(CharT);
        std::uint32_t toRead = a_count * size;
        _absoluteCurrentPos += _readFn(this, a_str, toRead, &size, 1);
        return true;
    }

    virtual ~NiBinaryStream();

    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t unknown0C;            // 0C
    ReadFn*       _readFn;              // 10
};
static_assert(sizeof(NiBinaryStream) == 0x18, "NiBinaryStream size, the unit reads only these slots");

class NiStream
{
public:
    virtual ~NiStream();

    std::uint8_t unknown08[0xF8];   // 08
    std::uint32_t nifMaxVersion;    // 100
    std::uint32_t nifMaxUserDefinedVersion;  // 104
    std::uint8_t unknown108[0x190]; // 108
    NiBinaryStream* iStr;       // 298

    void LoadFixedStringLegacy(BSFixedString& a_string);
};
static_assert(sizeof(NiStream) == 0x2A0, "NiStream size up to iStr");

class BSTextureSet : public NiObject
{
public:
};
static_assert(sizeof(BSTextureSet) == 0x10, "BSTextureSet size");

class BSShaderTextureSet : public BSTextureSet
{
public:
    virtual void LoadBinary(NiStream& a_stream) override;  // compared: 0x153b1b0
    virtual bool IsEqual(NiObject* a_object) override;
    virtual const char* GetTexturePath(Texture a_texture);  // compared: 0x153b3c0

    // texturePaths, texturePathStrings: GUESS(low); the same nine slots at 0x10. GetTexturePath
    // reads them by index as plain pointers, and LoadBinary fills them as fixed strings.
    union
    {
        const char* texturePaths[0x9];            // 10
        BSFixedString texturePathStrings[0x9];    // 10
    };
};
static_assert(sizeof(BSShaderTextureSet) == 0x58, "BSShaderTextureSet size");
