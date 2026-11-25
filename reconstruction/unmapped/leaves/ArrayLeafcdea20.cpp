// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xcdea20 ArrayLeafcdea20::~ArrayLeafcdea20
// CI hash: 0xcdea20 ??1ArrayLeafcdea20@@QEAA@XZ
#include "ArrayLeafcdea20.h"

// guess: same compiled code as matched 0xcdea20 apart from relocated fields; its role here is not established.
ArrayLeafcdea20::~ArrayLeafcdea20()
{
    if (data) {
        FreeArrayLeafcdea20(this);
        size = 0;
    }
}
