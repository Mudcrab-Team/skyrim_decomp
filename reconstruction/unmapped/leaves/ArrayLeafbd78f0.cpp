// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xbd78f0 ArrayLeafbd78f0::~ArrayLeafbd78f0
// CI hash: 0xbd78f0 ??1ArrayLeafbd78f0@@QEAA@XZ
#include "ArrayLeafbd78f0.h"

// guess: same compiled code as matched 0xbd78f0 apart from relocated fields; its role here is not established.
ArrayLeafbd78f0::~ArrayLeafbd78f0()
{
    if (data) {
        FreeArrayLeafbd78f0(this);
        size = 0;
    }
}
