// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1179f30 ArrayLeaf1179f30::~ArrayLeaf1179f30
// CI hash: 0x1179f30 ??1ArrayLeaf1179f30@@QEAA@XZ
#include "ArrayLeaf1179f30.h"

// guess: same compiled code as matched 0x1179f30 apart from relocated fields; its role here is not established.
ArrayLeaf1179f30::~ArrayLeaf1179f30()
{
    if (data) {
        FreeArrayLeaf1179f30(this);
        size = 0;
    }
}
