// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x11e9440 ArrayLeaf11e9440::~ArrayLeaf11e9440
// CI hash: 0x11e9440 ??1ArrayLeaf11e9440@@QEAA@XZ
#include "ArrayLeaf11e9440.h"

// guess: same compiled code as matched 0x11e9440 apart from relocated fields; its role here is not established.
ArrayLeaf11e9440::~ArrayLeaf11e9440()
{
    if (data) {
        FreeArrayLeaf11e9440(this);
        size = 0;
    }
}
