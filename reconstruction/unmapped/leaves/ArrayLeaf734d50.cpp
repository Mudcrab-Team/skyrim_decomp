// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x734d50 ArrayLeaf734d50::~ArrayLeaf734d50
// CI hash: 0x734d50 ??1ArrayLeaf734d50@@QEAA@XZ
#include "ArrayLeaf734d50.h"

// guess: same compiled code as matched 0x734d50 apart from relocated fields; its role here is not established.
ArrayLeaf734d50::~ArrayLeaf734d50()
{
    if (data) {
        FreeArrayLeaf734d50(this);
        size = 0;
    }
}
