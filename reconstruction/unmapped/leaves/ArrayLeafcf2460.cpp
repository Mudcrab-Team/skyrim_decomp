// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xcf2460 ArrayLeafcf2460::~ArrayLeafcf2460
// CI hash: 0xcf2460 ??1ArrayLeafcf2460@@QEAA@XZ
#include "ArrayLeafcf2460.h"

// guess: same compiled code as matched 0xcf2460 apart from relocated fields; its role here is not established.
ArrayLeafcf2460::~ArrayLeafcf2460()
{
    if (data) {
        FreeArrayLeafcf2460(this);
        size = 0;
    }
}
