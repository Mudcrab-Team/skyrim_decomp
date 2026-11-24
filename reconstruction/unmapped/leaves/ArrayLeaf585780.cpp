// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x585780 ArrayLeaf585780::~ArrayLeaf585780
// CI hash: 0x585780 ??1ArrayLeaf585780@@QEAA@XZ
#include "ArrayLeaf585780.h"

// guess: same compiled code as matched 0x585780 apart from relocated fields; its role here is not established.
ArrayLeaf585780::~ArrayLeaf585780()
{
    if (data) {
        FreeArrayLeaf585780(this);
        size = 0;
    }
}
