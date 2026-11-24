// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x3eb260 ArrayLeaf3eb260::~ArrayLeaf3eb260
// CI hash: 0x3eb260 ??1ArrayLeaf3eb260@@QEAA@XZ
#include "ArrayLeaf3eb260.h"

// guess: same compiled code as matched 0x3eb260 apart from relocated fields; its role here is not established.
ArrayLeaf3eb260::~ArrayLeaf3eb260()
{
    if (data) {
        FreeArrayLeaf3eb260(this);
        size = 0;
    }
}
