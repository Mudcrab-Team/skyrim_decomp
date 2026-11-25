// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xfc3fc0 ArrayLeaffc3fc0::~ArrayLeaffc3fc0
// CI hash: 0xfc3fc0 ??1ArrayLeaffc3fc0@@QEAA@XZ
#include "ArrayLeaffc3fc0.h"

// guess: same compiled code as matched 0xfc3fc0 apart from relocated fields; its role here is not established.
ArrayLeaffc3fc0::~ArrayLeaffc3fc0()
{
    if (data) {
        FreeArrayLeaffc3fc0(this);
        size = 0;
    }
}
