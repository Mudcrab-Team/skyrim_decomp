// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x585720 ArrayLeaf585720::~ArrayLeaf585720
// CI hash: 0x585720 ??1ArrayLeaf585720@@QEAA@XZ
#include "ArrayLeaf585720.h"

// guess: same compiled code as matched 0x585720 apart from relocated fields; its role here is not established.
ArrayLeaf585720::~ArrayLeaf585720()
{
    if (data) {
        FreeArrayLeaf585720(this);
        size = 0;
    }
}
