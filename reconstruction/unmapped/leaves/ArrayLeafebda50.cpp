// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xebda50 ArrayLeafebda50::~ArrayLeafebda50
// CI hash: 0xebda50 ??1ArrayLeafebda50@@QEAA@XZ
#include "ArrayLeafebda50.h"

// guess: same compiled code as matched 0xebda50 apart from relocated fields; its role here is not established.
ArrayLeafebda50::~ArrayLeafebda50()
{
    if (data) {
        FreeArrayLeafebda50(this);
        size = 0;
    }
}
