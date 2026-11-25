// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xed0310 ArrayLeafed0310::~ArrayLeafed0310
// CI hash: 0xed0310 ??1ArrayLeafed0310@@QEAA@XZ
#include "ArrayLeafed0310.h"

// guess: same compiled code as matched 0xed0310 apart from relocated fields; its role here is not established.
ArrayLeafed0310::~ArrayLeafed0310()
{
    if (data) {
        FreeArrayLeafed0310(this);
        size = 0;
    }
}
