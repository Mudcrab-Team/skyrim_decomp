// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x981c50 ArrayLeaf981c50::~ArrayLeaf981c50
// CI hash: 0x981c50 ??1ArrayLeaf981c50@@QEAA@XZ
#include "ArrayLeaf981c50.h"

// guess: same compiled code as matched 0x981c50 apart from relocated fields; its role here is not established.
ArrayLeaf981c50::~ArrayLeaf981c50()
{
    if (data) {
        FreeArrayLeaf981c50(this);
        size = 0;
    }
}
