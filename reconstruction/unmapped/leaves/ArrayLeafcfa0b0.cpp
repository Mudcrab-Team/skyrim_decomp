// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xcfa0b0 ArrayLeafcfa0b0::~ArrayLeafcfa0b0
// CI hash: 0xcfa0b0 ??1ArrayLeafcfa0b0@@QEAA@XZ
#include "ArrayLeafcfa0b0.h"

// guess: same compiled code as matched 0xcfa0b0 apart from relocated fields; its role here is not established.
ArrayLeafcfa0b0::~ArrayLeafcfa0b0()
{
    if (data) {
        FreeArrayLeafcfa0b0(this);
        size = 0;
    }
}
