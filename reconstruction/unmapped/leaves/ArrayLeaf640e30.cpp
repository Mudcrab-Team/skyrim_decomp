// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x640e30 ArrayLeaf640e30::~ArrayLeaf640e30
// CI hash: 0x640e30 ??1ArrayLeaf640e30@@QEAA@XZ
#include "ArrayLeaf640e30.h"

// guess: same compiled code as matched 0x640e30 apart from relocated fields; its role here is not established.
ArrayLeaf640e30::~ArrayLeaf640e30()
{
    if (data) {
        FreeArrayLeaf640e30(this);
        size = 0;
    }
}
