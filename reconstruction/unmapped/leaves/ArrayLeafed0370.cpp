// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xed0370 ArrayLeafed0370::~ArrayLeafed0370
// CI hash: 0xed0370 ??1ArrayLeafed0370@@QEAA@XZ
#include "ArrayLeafed0370.h"

// guess: same compiled code as matched 0xed0370 apart from relocated fields; its role here is not established.
ArrayLeafed0370::~ArrayLeafed0370()
{
    if (data) {
        FreeArrayLeafed0370(this);
        size = 0;
    }
}
