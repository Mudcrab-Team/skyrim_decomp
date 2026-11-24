// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x646d00 ArrayLeaf646d00::~ArrayLeaf646d00
// CI hash: 0x646d00 ??1ArrayLeaf646d00@@QEAA@XZ
#include "ArrayLeaf646d00.h"

// guess: same compiled code as matched 0x646d00 apart from relocated fields; its role here is not established.
ArrayLeaf646d00::~ArrayLeaf646d00()
{
    if (data) {
        FreeArrayLeaf646d00(this);
        size = 0;
    }
}
