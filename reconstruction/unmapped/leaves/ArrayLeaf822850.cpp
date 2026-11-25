// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x822850 ArrayLeaf822850::~ArrayLeaf822850
// CI hash: 0x822850 ??1ArrayLeaf822850@@QEAA@XZ
#include "ArrayLeaf822850.h"

// guess: same compiled code as matched 0x822850 apart from relocated fields; its role here is not established.
ArrayLeaf822850::~ArrayLeaf822850()
{
    if (data) {
        FreeArrayLeaf822850(this);
        size = 0;
    }
}
