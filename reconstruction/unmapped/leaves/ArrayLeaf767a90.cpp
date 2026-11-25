// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x767a90 ArrayLeaf767a90::~ArrayLeaf767a90
// CI hash: 0x767a90 ??1ArrayLeaf767a90@@QEAA@XZ
#include "ArrayLeaf767a90.h"

// guess: same compiled code as matched 0x767a90 apart from relocated fields; its role here is not established.
ArrayLeaf767a90::~ArrayLeaf767a90()
{
    if (data) {
        FreeArrayLeaf767a90(this);
        size = 0;
    }
}
