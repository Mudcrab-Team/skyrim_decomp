// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x5f2230 ArrayLeaf5f2230::~ArrayLeaf5f2230
// CI hash: 0x5f2230 ??1ArrayLeaf5f2230@@QEAA@XZ
#include "ArrayLeaf5f2230.h"

// guess: same compiled code as matched 0x5f2230 apart from relocated fields; its role here is not established.
ArrayLeaf5f2230::~ArrayLeaf5f2230()
{
    if (data) {
        FreeArrayLeaf5f2230(this);
        size = 0;
    }
}
