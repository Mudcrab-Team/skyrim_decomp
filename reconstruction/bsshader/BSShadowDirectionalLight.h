// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSShadowDirectionalLight: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSLight, BSShadowLight: STANDIN EXE_RTTI
// BSShadowDirectionalLight::GetPassExtraParam: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown10, unknown140, unknown560: GUESS(low)
#pragma once

#include <cstdint>
#include "../gamebryo/nimain/NiRefObject.h"

// ArrayStorage, ArraySize, ShadowArray, FreeArrayStorage: GUESS(low); a stand-in for a dynamic array modelled as its
// allocator part (data pointer and capacity) and its size part at offset 0x10, each with an empty out-of-line destructor
struct ArrayStorage
{
    ~ArrayStorage();
    void* data;  // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;  // 0C
};

struct ArraySize
{
    ~ArraySize();
    std::uint32_t size;  // 00
    std::uint32_t pad04;  // 04
};

struct ShadowArray : public ArrayStorage, public ArraySize
{
    ~ShadowArray();
};

void FreeArrayStorage(ShadowArray* a_array);

class BSLight : public NiRefObject
{
public:
    std::uint8_t unknown10[0x130];  // 10
};
static_assert(sizeof(BSLight) == 0x140, "BSLight size");

class BSShadowLight : public BSLight
{
public:
    std::uint8_t unknown140[0x420];  // 140
};
static_assert(sizeof(BSShadowLight) == 0x560, "BSShadowLight size");

class BSShadowDirectionalLight : public BSShadowLight
{
public:
    virtual std::uint32_t GetPassExtraParam(std::uint32_t a_accumFlag);  // compared: 0x157ed10
    // GetIsFrustumOrDirectionalLight, GetIsDirectionalLight, GetNeedsClipPlanes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); each returns true
    virtual bool GetIsFrustumOrDirectionalLight();
    virtual bool GetIsDirectionalLight();
    virtual bool GetNeedsClipPlanes();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown560[0x58];  // 560
};
static_assert(sizeof(BSShadowDirectionalLight) == 0x5B8, "BSShadowDirectionalLight size");
