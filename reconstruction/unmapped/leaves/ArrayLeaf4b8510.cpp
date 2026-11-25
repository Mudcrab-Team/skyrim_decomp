// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x4b8510 ArrayLeaf4b8510::~ArrayLeaf4b8510
// CI hash: 0x4b8510 ??1ArrayLeaf4b8510@@QEAA@XZ
#include "ArrayLeaf4b8510.h"

// guess: same compiled code as matched 0x4b8510 apart from relocated fields; its role here is not established.
ArrayLeaf4b8510::~ArrayLeaf4b8510()
{
    if (data) {
        FreeArrayLeaf4b8510(this);
        size = 0;
    }
}
