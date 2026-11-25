// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x55c0e0 ArrayLeaf55c0e0::~ArrayLeaf55c0e0
// CI hash: 0x55c0e0 ??1ArrayLeaf55c0e0@@QEAA@XZ
#include "ArrayLeaf55c0e0.h"

// guess: same compiled code as matched 0x55c0e0 apart from relocated fields; its role here is not established.
ArrayLeaf55c0e0::~ArrayLeaf55c0e0()
{
    if (data) {
        FreeArrayLeaf55c0e0(this);
        size = 0;
    }
}
