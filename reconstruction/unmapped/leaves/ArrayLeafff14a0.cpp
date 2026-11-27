// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xff14a0 ArrayLeafff14a0::~ArrayLeafff14a0
// CI hash: 0xff14a0 ??1ArrayLeafff14a0@@QEAA@XZ
#include "ArrayLeafff14a0.h"

// guess: same compiled code as matched 0xff14a0 apart from relocated fields; its role here is not established.
ArrayLeafff14a0::~ArrayLeafff14a0()
{
    if (data) {
        FreeArrayLeafff14a0(this);
        size = 0;
    }
}
