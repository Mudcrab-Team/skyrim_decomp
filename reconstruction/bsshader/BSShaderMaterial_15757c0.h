// Source exposure: mixed (pinned image and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original checksum body; typed declarations adapted from existing shader-material units. Adapted bodies: none.
// BSShaderMaterial, ComputeCRC32, Create, CopyMembers, DoIsCopy, GetDefault, GetFeature, GetType, texCoordOffset, texCoordScale, hashKey: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// seed, ChecksumFields, zero, CRC32Bytes_ce2510, NiPoint2, fields: GUESS(low) STANDIN; the compared helper consumes a seed argument.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <cstddef>
#include <cstdint>

struct NiPoint2 { float x; float y; };
// BSIntrusiveRefCounted: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSIntrusiveRefCounted
{
    // volatile: follows the pinned intrusive reference-count declaration.
    mutable volatile std::uint32_t _refCount{0};
};
class BSShaderMaterial : public BSIntrusiveRefCounted
{
public:
    enum class Feature { kDefault = 0 };
    enum class Type { kBase = 0, kEffect = 1, kLighting = 2, kWater = 3 };
    BSShaderMaterial();
    static void* operator new(std::size_t size);
    virtual ~BSShaderMaterial();
    virtual BSShaderMaterial* Create();
    virtual void CopyMembers(BSShaderMaterial*);
    virtual bool DoIsCopy(BSShaderMaterial*);
    virtual unsigned int ComputeCRC32(unsigned int seed);
    virtual BSShaderMaterial* GetDefault();
    virtual Feature GetFeature() const;
    virtual Type GetType() const;
    NiPoint2 texCoordOffset[2];
    NiPoint2 texCoordScale[2];
    std::uint32_t hashKey;
    std::uint32_t unrecovered30;
    std::uint32_t unrecovered34;
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "material layout");

extern "C" void CRC32Bytes_ce2510(unsigned int* result, const void* fields, unsigned int size);
