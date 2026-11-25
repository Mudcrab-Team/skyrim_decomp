// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x93b710 ArrayLeaf93b710::~ArrayLeaf93b710
// CI hash: 0x93b710 ??1ArrayLeaf93b710@@QEAA@XZ
#include "ArrayLeaf93b710.h"

// guess: same compiled code as matched 0x93b710 apart from relocated fields; its role here is not established.
ArrayLeaf93b710::~ArrayLeaf93b710()
{
    if (data) {
        FreeArrayLeaf93b710(this);
        size = 0;
    }
}
