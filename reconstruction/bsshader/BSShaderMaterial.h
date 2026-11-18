// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShaderMaterial::CopyMembers, BSShaderMaterial::~BSShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RawAt, BSShaderPair: GUESS(low)
// unknown08, unknown2C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

template <class T>
T& RawAt(const void* a_base, std::ptrdiff_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_base)) + a_offset);
}

struct BSShaderPair
{
    float first;   // 00
    float second;  // 04
};

// BSShaderMaterial::Feature, BSShaderMaterial::Type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the underlying type is a stand-in of four bytes, and only the zero value is used
// BSShaderMaterial::GetFeature, BSShaderMaterial::GetType, BSShaderMaterial::GetDefault: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x1556680, 0x1575920, 0x1575820
// gDefaultShaderMaterial: GUESS(low); the global read by GetDefault at RVA 0x3698be8, bound by hint
class BSShaderMaterial;
extern BSShaderMaterial* gDefaultShaderMaterial;

class BSShaderMaterial
{
public:
    enum class Feature : std::uint32_t { kDefault = 0 };
    enum class Type : std::uint32_t {};

    BSShaderMaterial();
    virtual void CopyMembers(BSShaderMaterial* a_other);  // compared: 0x1575700
    virtual ~BSShaderMaterial() {}  // compared: 0x15758f0 (scalar deleting destructor)
    virtual Feature GetFeature() const;  // compared: 0x1556680
    virtual Type GetType() const;  // compared: 0x1575920
    virtual BSShaderMaterial* GetDefault();  // compared: 0x1575820

    std::uint8_t unknown08[0x30];  // 08
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "BSShaderMaterial size");
