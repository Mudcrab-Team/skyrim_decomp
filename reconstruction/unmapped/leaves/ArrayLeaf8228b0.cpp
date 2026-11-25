// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x8228b0 ArrayLeaf8228b0::~ArrayLeaf8228b0
// CI hash: 0x8228b0 ??1ArrayLeaf8228b0@@QEAA@XZ
#include "ArrayLeaf8228b0.h"

// guess: same compiled code as matched 0x8228b0 apart from relocated fields; its role here is not established.
ArrayLeaf8228b0::~ArrayLeaf8228b0()
{
    if (data) {
        FreeArrayLeaf8228b0(this);
        size = 0;
    }
}
