// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x6ba350 ArrayLeaf6ba350::~ArrayLeaf6ba350
// CI hash: 0x6ba350 ??1ArrayLeaf6ba350@@QEAA@XZ
#include "ArrayLeaf6ba350.h"

// guess: same compiled code as matched 0x6ba350 apart from relocated fields; its role here is not established.
ArrayLeaf6ba350::~ArrayLeaf6ba350()
{
    if (data) {
        FreeArrayLeaf6ba350(this);
        size = 0;
    }
}
