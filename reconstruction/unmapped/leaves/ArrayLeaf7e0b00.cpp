// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x7e0b00 ArrayLeaf7e0b00::~ArrayLeaf7e0b00
// CI hash: 0x7e0b00 ??1ArrayLeaf7e0b00@@QEAA@XZ
#include "ArrayLeaf7e0b00.h"

// guess: same compiled code as matched 0x7e0b00 apart from relocated fields; its role here is not established.
ArrayLeaf7e0b00::~ArrayLeaf7e0b00()
{
    if (data) {
        FreeArrayLeaf7e0b00(this);
        size = 0;
    }
}
