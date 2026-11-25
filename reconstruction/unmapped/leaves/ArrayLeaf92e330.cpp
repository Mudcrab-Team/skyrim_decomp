// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x92e330 ArrayLeaf92e330::~ArrayLeaf92e330
// CI hash: 0x92e330 ??1ArrayLeaf92e330@@QEAA@XZ
#include "ArrayLeaf92e330.h"

// guess: same compiled code as matched 0x92e330 apart from relocated fields; its role here is not established.
ArrayLeaf92e330::~ArrayLeaf92e330()
{
    if (data) {
        FreeArrayLeaf92e330(this);
        size = 0;
    }
}
