// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1202450 ArrayLeaf1202450::~ArrayLeaf1202450
// CI hash: 0x1202450 ??1ArrayLeaf1202450@@QEAA@XZ
#include "ArrayLeaf1202450.h"

// guess: same compiled code as matched 0x1202450 apart from relocated fields; its role here is not established.
ArrayLeaf1202450::~ArrayLeaf1202450()
{
    if (data) {
        FreeArrayLeaf1202450(this);
        size = 0;
    }
}
