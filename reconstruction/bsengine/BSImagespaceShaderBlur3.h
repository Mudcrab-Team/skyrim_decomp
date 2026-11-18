// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSImagespaceShaderBlur3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShader, BSImagespaceShader: STANDIN EXE_RTTI
// BSImagespaceShaderBlur3::~BSImagespaceShaderBlur3, BSImagespaceShaderBlur3::Unk_0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the listing shows Unk_0D returns a six-pointer table through a hidden pointer (the community excerpt says void)
// BSImagespaceShaderBlur3Table: GUESS(low)
// g_blurDataA, g_blurDataB: GUESS(low)
// unknown10, unknown90: GUESS(low)
#pragma once

#include <cstdint>
#include "../netimmerse/NiRefObject.h"

struct BSImagespaceShaderBlur3Table
{
    const char* name00;  // 00
    void* data08;  // 08
    const char* name10;  // 10
    void* data18;  // 18
    void* ptr20;  // 20
    void* ptr28;  // 28
};

extern std::uint8_t g_blurDataA;
extern std::uint8_t g_blurDataB;

class BSShader : public NiRefObject
{
public:
    std::uint8_t unknown10[0x80];  // 10
};
static_assert(sizeof(BSShader) == 0x90, "BSShader size");

class BSImagespaceShader : public BSShader
{
public:
    std::uint8_t unknown90[0x118];  // 90
};
static_assert(sizeof(BSImagespaceShader) == 0x1A8, "BSImagespaceShader size");

class BSImagespaceShaderBlur3 : public BSImagespaceShader
{
public:
    BSImagespaceShaderBlur3();
    virtual ~BSImagespaceShaderBlur3();  // compared: 0x1507e00 (scalar deleting destructor)
    virtual BSImagespaceShaderBlur3Table Unk_0D();  // compared: 0x1509cb0
};
static_assert(sizeof(BSImagespaceShaderBlur3) == 0x1A8, "BSImagespaceShaderBlur3 size");
