// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x98c340 ArrayLeaf98c340::~ArrayLeaf98c340
// CI hash: 0x98c340 ??1ArrayLeaf98c340@@QEAA@XZ
#include "ArrayLeaf98c340.h"

// guess: same compiled code as matched 0x98c340 apart from relocated fields; its role here is not established.
ArrayLeaf98c340::~ArrayLeaf98c340()
{
    if (data) {
        FreeArrayLeaf98c340(this);
        size = 0;
    }
}
