// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x101ed50 ArrayLeaf101ed50::~ArrayLeaf101ed50
// CI hash: 0x101ed50 ??1ArrayLeaf101ed50@@QEAA@XZ
#include "ArrayLeaf101ed50.h"

// guess: same compiled code as matched 0x101ed50 apart from relocated fields; its role here is not established.
ArrayLeaf101ed50::~ArrayLeaf101ed50()
{
    if (data) {
        FreeArrayLeaf101ed50(this);
        size = 0;
    }
}
