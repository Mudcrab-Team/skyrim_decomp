// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x767490 ArrayLeaf767490::~ArrayLeaf767490
// CI hash: 0x767490 ??1ArrayLeaf767490@@QEAA@XZ
#include "ArrayLeaf767490.h"

// guess: same compiled code as matched 0x767490 apart from relocated fields; its role here is not established.
ArrayLeaf767490::~ArrayLeaf767490()
{
    if (data) {
        FreeArrayLeaf767490(this);
        size = 0;
    }
}
