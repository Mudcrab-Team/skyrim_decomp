// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xeda730 ArrayLeafeda730::~ArrayLeafeda730
// CI hash: 0xeda730 ??1ArrayLeafeda730@@QEAA@XZ
#include "ArrayLeafeda730.h"

// guess: same compiled code as matched 0xeda730 apart from relocated fields; its role here is not established.
ArrayLeafeda730::~ArrayLeafeda730()
{
    if (data) {
        FreeArrayLeafeda730(this);
        size = 0;
    }
}
