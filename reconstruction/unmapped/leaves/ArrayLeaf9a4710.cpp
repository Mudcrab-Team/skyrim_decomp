// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x9a4710 ArrayLeaf9a4710::~ArrayLeaf9a4710
// CI hash: 0x9a4710 ??1ArrayLeaf9a4710@@QEAA@XZ
#include "ArrayLeaf9a4710.h"

// guess: same compiled code as matched 0x9a4710 apart from relocated fields; its role here is not established.
ArrayLeaf9a4710::~ArrayLeaf9a4710()
{
    if (data) {
        FreeArrayLeaf9a4710(this);
        size = 0;
    }
}
