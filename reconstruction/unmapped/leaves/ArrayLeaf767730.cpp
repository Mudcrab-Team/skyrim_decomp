// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x767730 ArrayLeaf767730::~ArrayLeaf767730
// CI hash: 0x767730 ??1ArrayLeaf767730@@QEAA@XZ
#include "ArrayLeaf767730.h"

// guess: same compiled code as matched 0x767730 apart from relocated fields; its role here is not established.
ArrayLeaf767730::~ArrayLeaf767730()
{
    if (data) {
        FreeArrayLeaf767730(this);
        size = 0;
    }
}
