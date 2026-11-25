// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x8ba240 ArrayLeaf8ba240::~ArrayLeaf8ba240
// CI hash: 0x8ba240 ??1ArrayLeaf8ba240@@QEAA@XZ
#include "ArrayLeaf8ba240.h"

// guess: same compiled code as matched 0x8ba240 apart from relocated fields; its role here is not established.
ArrayLeaf8ba240::~ArrayLeaf8ba240()
{
    if (data) {
        FreeArrayLeaf8ba240(this);
        size = 0;
    }
}
