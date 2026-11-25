// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x955760 ArrayLeaf955760::~ArrayLeaf955760
// CI hash: 0x955760 ??1ArrayLeaf955760@@QEAA@XZ
#include "ArrayLeaf955760.h"

// guess: same compiled code as matched 0x955760 apart from relocated fields; its role here is not established.
ArrayLeaf955760::~ArrayLeaf955760()
{
    if (data) {
        FreeArrayLeaf955760(this);
        size = 0;
    }
}
