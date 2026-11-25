// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1561d10 ArrayLeaf1561d10::~ArrayLeaf1561d10
// CI hash: 0x1561d10 ??1ArrayLeaf1561d10@@QEAA@XZ
#include "ArrayLeaf1561d10.h"

// guess: same compiled code as matched 0x1561d10 apart from relocated fields; its role here is not established.
ArrayLeaf1561d10::~ArrayLeaf1561d10()
{
    if (data) {
        FreeArrayLeaf1561d10(this);
        size = 0;
    }
}
