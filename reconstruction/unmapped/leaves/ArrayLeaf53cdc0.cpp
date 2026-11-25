// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x53cdc0 ArrayLeaf53cdc0::~ArrayLeaf53cdc0
// CI hash: 0x53cdc0 ??1ArrayLeaf53cdc0@@QEAA@XZ
#include "ArrayLeaf53cdc0.h"

// guess: same compiled code as matched 0x53cdc0 apart from relocated fields; its role here is not established.
ArrayLeaf53cdc0::~ArrayLeaf53cdc0()
{
    if (data) {
        FreeArrayLeaf53cdc0(this);
        size = 0;
    }
}
