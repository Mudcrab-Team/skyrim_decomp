// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x904300 ArrayLeaf904300::~ArrayLeaf904300
// CI hash: 0x904300 ??1ArrayLeaf904300@@QEAA@XZ
#include "ArrayLeaf904300.h"

// guess: same compiled code as matched 0x904300 apart from relocated fields; its role here is not established.
ArrayLeaf904300::~ArrayLeaf904300()
{
    if (data) {
        FreeArrayLeaf904300(this);
        size = 0;
    }
}
