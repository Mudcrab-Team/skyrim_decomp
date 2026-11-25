// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x4d2c70 ArrayLeaf4d2c70::~ArrayLeaf4d2c70
// CI hash: 0x4d2c70 ??1ArrayLeaf4d2c70@@QEAA@XZ
#include "ArrayLeaf4d2c70.h"

// guess: same compiled code as matched 0x4d2c70 apart from relocated fields; its role here is not established.
ArrayLeaf4d2c70::~ArrayLeaf4d2c70()
{
    if (data) {
        FreeArrayLeaf4d2c70(this);
        size = 0;
    }
}
