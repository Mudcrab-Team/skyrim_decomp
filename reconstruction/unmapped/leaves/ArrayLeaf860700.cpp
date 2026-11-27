// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x860700 ArrayLeaf860700::~ArrayLeaf860700
// CI hash: 0x860700 ??1ArrayLeaf860700@@QEAA@XZ
#include "ArrayLeaf860700.h"

// guess: same compiled code as matched 0x860700 apart from relocated fields; its role here is not established.
ArrayLeaf860700::~ArrayLeaf860700()
{
    if (data) {
        FreeArrayLeaf860700(this);
        size = 0;
    }
}
