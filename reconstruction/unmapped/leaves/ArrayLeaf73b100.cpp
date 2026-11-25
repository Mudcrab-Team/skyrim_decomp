// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x73b100 ArrayLeaf73b100::~ArrayLeaf73b100
// CI hash: 0x73b100 ??1ArrayLeaf73b100@@QEAA@XZ
#include "ArrayLeaf73b100.h"

// guess: same compiled code as matched 0x73b100 apart from relocated fields; its role here is not established.
ArrayLeaf73b100::~ArrayLeaf73b100()
{
    if (data) {
        FreeArrayLeaf73b100(this);
        size = 0;
    }
}
