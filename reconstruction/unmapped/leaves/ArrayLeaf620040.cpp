// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x620040 ArrayLeaf620040::~ArrayLeaf620040
// CI hash: 0x620040 ??1ArrayLeaf620040@@QEAA@XZ
#include "ArrayLeaf620040.h"

// guess: same compiled code as matched 0x620040 apart from relocated fields; its role here is not established.
ArrayLeaf620040::~ArrayLeaf620040()
{
    if (data) {
        FreeArrayLeaf620040(this);
        size = 0;
    }
}
