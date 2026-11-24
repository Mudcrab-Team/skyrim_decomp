// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x11f1e20 ArrayLeaf11f1e20::~ArrayLeaf11f1e20
// CI hash: 0x11f1e20 ??1ArrayLeaf11f1e20@@QEAA@XZ
#include "ArrayLeaf11f1e20.h"

// guess: same compiled code as matched 0x11f1e20 apart from relocated fields; its role here is not established.
ArrayLeaf11f1e20::~ArrayLeaf11f1e20()
{
    if (data) {
        FreeArrayLeaf11f1e20(this);
        size = 0;
    }
}
