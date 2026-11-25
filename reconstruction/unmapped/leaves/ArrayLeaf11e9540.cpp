// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x11e9540 ArrayLeaf11e9540::~ArrayLeaf11e9540
// CI hash: 0x11e9540 ??1ArrayLeaf11e9540@@QEAA@XZ
#include "ArrayLeaf11e9540.h"

// guess: same compiled code as matched 0x11e9540 apart from relocated fields; its role here is not established.
ArrayLeaf11e9540::~ArrayLeaf11e9540()
{
    if (data) {
        FreeArrayLeaf11e9540(this);
        size = 0;
    }
}
