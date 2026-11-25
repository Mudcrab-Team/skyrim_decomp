// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xceb420 ArrayLeafceb420::~ArrayLeafceb420
// CI hash: 0xceb420 ??1ArrayLeafceb420@@QEAA@XZ
#include "ArrayLeafceb420.h"

// guess: same compiled code as matched 0xceb420 apart from relocated fields; its role here is not established.
ArrayLeafceb420::~ArrayLeafceb420()
{
    if (data) {
        FreeArrayLeafceb420(this);
        size = 0;
    }
}
