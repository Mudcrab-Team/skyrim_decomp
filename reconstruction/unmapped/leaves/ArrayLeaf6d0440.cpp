// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x6d0440 ArrayLeaf6d0440::~ArrayLeaf6d0440
// CI hash: 0x6d0440 ??1ArrayLeaf6d0440@@QEAA@XZ
#include "ArrayLeaf6d0440.h"

// guess: same compiled code as matched 0x6d0440 apart from relocated fields; its role here is not established.
ArrayLeaf6d0440::~ArrayLeaf6d0440()
{
    if (data) {
        FreeArrayLeaf6d0440(this);
        size = 0;
    }
}
