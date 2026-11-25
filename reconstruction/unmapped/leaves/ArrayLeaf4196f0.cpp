// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x4196f0 ArrayLeaf4196f0::~ArrayLeaf4196f0
// CI hash: 0x4196f0 ??1ArrayLeaf4196f0@@QEAA@XZ
#include "ArrayLeaf4196f0.h"

// guess: same compiled code as matched 0x4196f0 apart from relocated fields; its role here is not established.
ArrayLeaf4196f0::~ArrayLeaf4196f0()
{
    if (data) {
        FreeArrayLeaf4196f0(this);
        size = 0;
    }
}
