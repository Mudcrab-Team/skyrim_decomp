// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x12501c0 ArrayLeaf12501c0::~ArrayLeaf12501c0
// CI hash: 0x12501c0 ??1ArrayLeaf12501c0@@QEAA@XZ
#include "ArrayLeaf12501c0.h"

// guess: same compiled code as matched 0x12501c0 apart from relocated fields; its role here is not established.
ArrayLeaf12501c0::~ArrayLeaf12501c0()
{
    if (data) {
        FreeArrayLeaf12501c0(this);
        size = 0;
    }
}
