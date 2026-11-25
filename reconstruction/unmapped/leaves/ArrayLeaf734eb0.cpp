// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x734eb0 ArrayLeaf734eb0::~ArrayLeaf734eb0
// CI hash: 0x734eb0 ??1ArrayLeaf734eb0@@QEAA@XZ
#include "ArrayLeaf734eb0.h"

// guess: same compiled code as matched 0x734eb0 apart from relocated fields; its role here is not established.
ArrayLeaf734eb0::~ArrayLeaf734eb0()
{
    if (data) {
        FreeArrayLeaf734eb0(this);
        size = 0;
    }
}
