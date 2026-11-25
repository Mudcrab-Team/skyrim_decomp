// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xcfa110 ArrayLeafcfa110::~ArrayLeafcfa110
// CI hash: 0xcfa110 ??1ArrayLeafcfa110@@QEAA@XZ
#include "ArrayLeafcfa110.h"

// guess: same compiled code as matched 0xcfa110 apart from relocated fields; its role here is not established.
ArrayLeafcfa110::~ArrayLeafcfa110()
{
    if (data) {
        FreeArrayLeafcfa110(this);
        size = 0;
    }
}
