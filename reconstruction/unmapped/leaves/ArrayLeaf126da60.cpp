// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x126da60 ArrayLeaf126da60::~ArrayLeaf126da60
// CI hash: 0x126da60 ??1ArrayLeaf126da60@@QEAA@XZ
#include "ArrayLeaf126da60.h"

// guess: same compiled code as matched 0x126da60 apart from relocated fields; its role here is not established.
ArrayLeaf126da60::~ArrayLeaf126da60()
{
    if (data) {
        FreeArrayLeaf126da60(this);
        size = 0;
    }
}
