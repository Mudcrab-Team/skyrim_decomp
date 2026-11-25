// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x5d0140 ArrayLeaf5d0140::~ArrayLeaf5d0140
// CI hash: 0x5d0140 ??1ArrayLeaf5d0140@@QEAA@XZ
#include "ArrayLeaf5d0140.h"

// guess: same compiled code as matched 0x5d0140 apart from relocated fields; its role here is not established.
ArrayLeaf5d0140::~ArrayLeaf5d0140()
{
    if (data) {
        FreeArrayLeaf5d0140(this);
        size = 0;
    }
}
