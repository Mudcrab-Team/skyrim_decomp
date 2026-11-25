// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x779ae0 ArrayLeaf779ae0::~ArrayLeaf779ae0
// CI hash: 0x779ae0 ??1ArrayLeaf779ae0@@QEAA@XZ
#include "ArrayLeaf779ae0.h"

// guess: same compiled code as matched 0x779ae0 apart from relocated fields; its role here is not established.
ArrayLeaf779ae0::~ArrayLeaf779ae0()
{
    if (data) {
        FreeArrayLeaf779ae0(this);
        size = 0;
    }
}
