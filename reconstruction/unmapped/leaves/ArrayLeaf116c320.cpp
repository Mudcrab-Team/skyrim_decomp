// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x116c320 ArrayLeaf116c320::~ArrayLeaf116c320
// CI hash: 0x116c320 ??1ArrayLeaf116c320@@QEAA@XZ
#include "ArrayLeaf116c320.h"

// guess: same compiled code as matched 0x116c320 apart from relocated fields; its role here is not established.
ArrayLeaf116c320::~ArrayLeaf116c320()
{
    if (data) {
        FreeArrayLeaf116c320(this);
        size = 0;
    }
}
