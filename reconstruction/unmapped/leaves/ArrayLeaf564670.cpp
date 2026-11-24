// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x564670 ArrayLeaf564670::~ArrayLeaf564670
// CI hash: 0x564670 ??1ArrayLeaf564670@@QEAA@XZ
#include "ArrayLeaf564670.h"

// guess: same compiled code as matched 0x564670 apart from relocated fields; its role here is not established.
ArrayLeaf564670::~ArrayLeaf564670()
{
    if (data) {
        FreeArrayLeaf564670(this);
        size = 0;
    }
}
