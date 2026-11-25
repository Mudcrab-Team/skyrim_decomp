// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x94c930 ArrayLeaf94c930::~ArrayLeaf94c930
// CI hash: 0x94c930 ??1ArrayLeaf94c930@@QEAA@XZ
#include "ArrayLeaf94c930.h"

// guess: same compiled code as matched 0x94c930 apart from relocated fields; its role here is not established.
ArrayLeaf94c930::~ArrayLeaf94c930()
{
    if (data) {
        FreeArrayLeaf94c930(this);
        size = 0;
    }
}
