// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xbd7f20 ArrayLeafbd7f20::~ArrayLeafbd7f20
// CI hash: 0xbd7f20 ??1ArrayLeafbd7f20@@QEAA@XZ
#include "ArrayLeafbd7f20.h"

// guess: same compiled code as matched 0xbd7f20 apart from relocated fields; its role here is not established.
ArrayLeafbd7f20::~ArrayLeafbd7f20()
{
    if (data) {
        FreeArrayLeafbd7f20(this);
        size = 0;
    }
}
