// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x159b200 ArrayLeaf159b200::~ArrayLeaf159b200
// CI hash: 0x159b200 ??1ArrayLeaf159b200@@QEAA@XZ
#include "ArrayLeaf159b200.h"

// guess: same compiled code as matched 0x159b200 apart from relocated fields; its role here is not established.
ArrayLeaf159b200::~ArrayLeaf159b200()
{
    if (data) {
        FreeArrayLeaf159b200(this);
        size = 0;
    }
}
