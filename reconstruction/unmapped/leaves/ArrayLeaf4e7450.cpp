// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x4e7450 ArrayLeaf4e7450::~ArrayLeaf4e7450
// CI hash: 0x4e7450 ??1ArrayLeaf4e7450@@QEAA@XZ
#include "ArrayLeaf4e7450.h"

// guess: same compiled code as matched 0x4e7450 apart from relocated fields; its role here is not established.
ArrayLeaf4e7450::~ArrayLeaf4e7450()
{
    if (data) {
        FreeArrayLeaf4e7450(this);
        size = 0;
    }
}
