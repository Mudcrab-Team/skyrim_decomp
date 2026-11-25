// Source exposure: binary-analysis (assigned pinned-image pack; existing RTTI owner names).
// Code origin: original; no adapted body.
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderBlur13: EXE_RTTI
// BSImagespaceShaderBlur13::WriteShaderInfo, ShaderInfo, firstText, secondText, thirdText, fourthText, fifthText, sixthText: GUESS(low) STANDIN; six-pointer output shape, text roles unknown.
#pragma once
#include <cstddef>

struct ShaderInfo
{
    const char* firstText;
    const char* secondText;
    const char* thirdText;
    const char* fourthText;
    const char* fifthText;
    const char* sixthText;
};
static_assert(sizeof(ShaderInfo) == 0x30, "output size");
static_assert(offsetof(ShaderInfo, fourthText) == 0x18, "output offset");

class BSImagespaceShaderBlur13
{
public:
    ShaderInfo* WriteShaderInfo(ShaderInfo* output);
};
