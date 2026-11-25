// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x71bef0 ArrayLeaf71bef0::~ArrayLeaf71bef0
// CI hash: 0x71bef0 ??1ArrayLeaf71bef0@@QEAA@XZ
#include "ArrayLeaf71bef0.h"

// guess: same compiled code as matched 0x71bef0 apart from relocated fields; its role here is not established.
ArrayLeaf71bef0::~ArrayLeaf71bef0()
{
    if (data) {
        FreeArrayLeaf71bef0(this);
        size = 0;
    }
}
