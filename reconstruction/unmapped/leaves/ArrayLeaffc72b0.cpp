// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xfc72b0 ArrayLeaffc72b0::~ArrayLeaffc72b0
// CI hash: 0xfc72b0 ??1ArrayLeaffc72b0@@QEAA@XZ
#include "ArrayLeaffc72b0.h"

// guess: same compiled code as matched 0xfc72b0 apart from relocated fields; its role here is not established.
ArrayLeaffc72b0::~ArrayLeaffc72b0()
{
    if (data) {
        FreeArrayLeaffc72b0(this);
        size = 0;
    }
}
