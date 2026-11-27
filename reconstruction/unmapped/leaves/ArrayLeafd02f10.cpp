// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xd02f10 ArrayLeafd02f10::~ArrayLeafd02f10
// CI hash: 0xd02f10 ??1ArrayLeafd02f10@@QEAA@XZ
#include "ArrayLeafd02f10.h"

// guess: same compiled code as matched 0xd02f10 apart from relocated fields; its role here is not established.
ArrayLeafd02f10::~ArrayLeafd02f10()
{
    if (data) {
        FreeArrayLeafd02f10(this);
        size = 0;
    }
}
