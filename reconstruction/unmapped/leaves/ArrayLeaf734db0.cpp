// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x734db0 ArrayLeaf734db0::~ArrayLeaf734db0
// CI hash: 0x734db0 ??1ArrayLeaf734db0@@QEAA@XZ
#include "ArrayLeaf734db0.h"

// guess: same compiled code as matched 0x734db0 apart from relocated fields; its role here is not established.
ArrayLeaf734db0::~ArrayLeaf734db0()
{
    if (data) {
        FreeArrayLeaf734db0(this);
        size = 0;
    }
}
