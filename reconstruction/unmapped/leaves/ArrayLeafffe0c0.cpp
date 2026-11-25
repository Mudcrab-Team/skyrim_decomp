// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xffe0c0 ArrayLeafffe0c0::~ArrayLeafffe0c0
// CI hash: 0xffe0c0 ??1ArrayLeafffe0c0@@QEAA@XZ
#include "ArrayLeafffe0c0.h"

// guess: same compiled code as matched 0xffe0c0 apart from relocated fields; its role here is not established.
ArrayLeafffe0c0::~ArrayLeafffe0c0()
{
    if (data) {
        FreeArrayLeafffe0c0(this);
        size = 0;
    }
}
