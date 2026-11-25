// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xec9d80 ArrayLeafec9d80::~ArrayLeafec9d80
// CI hash: 0xec9d80 ??1ArrayLeafec9d80@@QEAA@XZ
#include "ArrayLeafec9d80.h"

// guess: same compiled code as matched 0xec9d80 apart from relocated fields; its role here is not established.
ArrayLeafec9d80::~ArrayLeafec9d80()
{
    if (data) {
        FreeArrayLeafec9d80(this);
        size = 0;
    }
}
