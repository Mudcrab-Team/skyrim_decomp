// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x603530 ArrayLeaf603530::~ArrayLeaf603530
// CI hash: 0x603530 ??1ArrayLeaf603530@@QEAA@XZ
#include "ArrayLeaf603530.h"

// guess: same compiled code as matched 0x603530 apart from relocated fields; its role here is not established.
ArrayLeaf603530::~ArrayLeaf603530()
{
    if (data) {
        FreeArrayLeaf603530(this);
        size = 0;
    }
}
