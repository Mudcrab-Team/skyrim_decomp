// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xbd7cf0 ArrayLeafbd7cf0::~ArrayLeafbd7cf0
// CI hash: 0xbd7cf0 ??1ArrayLeafbd7cf0@@QEAA@XZ
#include "ArrayLeafbd7cf0.h"

// guess: same compiled code as matched 0xbd7cf0 apart from relocated fields; its role here is not established.
ArrayLeafbd7cf0::~ArrayLeafbd7cf0()
{
    if (data) {
        FreeArrayLeafbd7cf0(this);
        size = 0;
    }
}
