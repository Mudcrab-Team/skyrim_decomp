// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1540f70 BSImagespaceShader::Function1540f70
// Adapted bodies: none
#include "BSImagespaceShader_1540f70.h"
#include <cstring>

uint64_t BSImagespaceShader::Function1540f70(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f)
{
    unk4c = d;
    unk50 = e;
    unk54 = f;
    std::memset(&unk58, 0, sizeof(unk58));
    unk40 = a;
    unk44 = b;
    unk48 = c;
    return unk58;
}
