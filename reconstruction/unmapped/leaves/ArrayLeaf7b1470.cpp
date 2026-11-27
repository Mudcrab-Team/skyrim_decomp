// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x7b1470 ArrayLeaf7b1470::~ArrayLeaf7b1470
// CI hash: 0x7b1470 ??1ArrayLeaf7b1470@@QEAA@XZ
#include "ArrayLeaf7b1470.h"

// guess: same compiled code as matched 0x7b1470 apart from relocated fields; its role here is not established.
ArrayLeaf7b1470::~ArrayLeaf7b1470()
{
    if (data) {
        FreeArrayLeaf7b1470(this);
        size = 0;
    }
}
