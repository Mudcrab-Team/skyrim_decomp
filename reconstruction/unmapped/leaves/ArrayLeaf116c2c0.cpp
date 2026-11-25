// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x116c2c0 ArrayLeaf116c2c0::~ArrayLeaf116c2c0
// CI hash: 0x116c2c0 ??1ArrayLeaf116c2c0@@QEAA@XZ
#include "ArrayLeaf116c2c0.h"

// guess: same compiled code as matched 0x116c2c0 apart from relocated fields; its role here is not established.
ArrayLeaf116c2c0::~ArrayLeaf116c2c0()
{
    if (data) {
        FreeArrayLeaf116c2c0(this);
        size = 0;
    }
}
