// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x874420 ArrayLeaf874420::~ArrayLeaf874420
// CI hash: 0x874420 ??1ArrayLeaf874420@@QEAA@XZ
#include "ArrayLeaf874420.h"

// guess: same compiled code as matched 0x874420 apart from relocated fields; its role here is not established.
ArrayLeaf874420::~ArrayLeaf874420()
{
    if (data) {
        FreeArrayLeaf874420(this);
        size = 0;
    }
}
