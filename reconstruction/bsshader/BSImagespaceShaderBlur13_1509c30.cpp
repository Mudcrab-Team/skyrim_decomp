// Source exposure: binary-analysis (assigned pinned-image pack; existing RTTI owner names).
// Code origin: original; no adapted body.
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderBlur13: EXE_RTTI
// BSImagespaceShaderBlur13::WriteShaderInfo, ShaderInfo, firstText, secondText, thirdText, fourthText, fifthText, sixthText: GUESS(low) STANDIN; six-pointer output shape, text roles unknown.
// kShaderInfoText0, kShaderInfoText1, kShaderInfoText2, kShaderInfoEmptyText: GUESS(low); opaque pack-bound text references.
// 0x1509c30 BSImagespaceShaderBlur13::WriteShaderInfo
#include "BSImagespaceShaderBlur13_1509c30.h"

extern const char kShaderInfoText0[];
extern const char kShaderInfoText1[];
extern const char kShaderInfoText2[];
extern const char kShaderInfoEmptyText[];

ShaderInfo* BSImagespaceShaderBlur13::WriteShaderInfo(ShaderInfo* output)
{
    output->firstText = kShaderInfoText0;
    output->secondText = kShaderInfoText1;
    output->thirdText = kShaderInfoText2;
    output->fourthText = kShaderInfoEmptyText;
    output->fifthText = nullptr;
    output->sixthText = nullptr;
    return output;
}
